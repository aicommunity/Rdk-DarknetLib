#ifndef RDK_TDarknetUBitmapClassifierCPP
#define RDK_TDarknetUBitmapClassifierCPP

#include "TDarknetUBitmapClassifier.h"
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

namespace RDK {

// Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------  //DetectionClass("DetectionClass",this),
TDarknetUBitmapClassifier::TDarknetUBitmapClassifier(void)
{
}

TDarknetUBitmapClassifier::~TDarknetUBitmapClassifier(void)
{
}
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
TDarknetUBitmapClassifier* TDarknetUBitmapClassifier::New(void)
{
    return new TDarknetUBitmapClassifier;
}
// --------------------------



// --------------------------
// Скрытые методы управления счетом
// --------------------------


// Восстановление настроек по умолчанию и сброс процесса счета
bool TDarknetUBitmapClassifier::ADNDefault(void)
{
    NumClasses=2;
    return true;
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool TDarknetUBitmapClassifier::ADNBuild(void)
{
 return true;
}

// Сброс процесса счета без потери настроек
bool TDarknetUBitmapClassifier::ADNReset(void)
{
 return true;
}

// Выполняет расчет этого объекта
bool TDarknetUBitmapClassifier::ADNCalculate(void)
{
    OutputClasses->Resize(0,1);
    OutputConfidences->Resize(0, NumClasses);
    if(InputImages.IsConnected() && InputImages->size()>0)
    {
        OutputClasses->Assign(InputImages->size(),1, CLASS_UNDEFINED);
        OutputConfidences->Assign(InputImages->size(), NumClasses,0.0);
        for(int i=0; i<InputImages->size(); i++)
        {
            ProcessedBmp = (*InputImages)[i];

            MDVector<double> output_confidences;
            int class_id;
            bool is_classified;
            bool classify_res=ClassifyBitmap(ProcessedBmp, output_confidences, ConfidenceThreshold, class_id, is_classified);

            if(classify_res)
            {
                for(int k=0; k<output_confidences.GetSize(); k++)
                {
                    (*OutputConfidences)(i, k) = output_confidences(k);
                }
                (*OutputClasses)[i] = (is_classified)?class_id:CLASS_LOWQUAL;
            }
        }
    }
    else
    {
        if(InputImage.IsConnected())
        {
            OutputClasses->Assign(1,1, CLASS_UNDEFINED);
            OutputConfidences->Assign(1, NumClasses,0.0);
            ProcessedBmp = *InputImage;

            MDVector<double> output_confidences;
            int class_id;
            bool is_classified;
            bool classify_res=ClassifyBitmap(ProcessedBmp, output_confidences, ConfidenceThreshold, class_id, is_classified);
            if(classify_res)
            {
                for(int k=0; k<output_confidences.GetSize(); k++)
                {
                    (*OutputConfidences)(0, k) = output_confidences(k);
                }
                (*OutputClasses)[0] = (is_classified)?class_id:CLASS_LOWQUAL;
            }
        }
    }

    return true;
}

bool TDarknetUBitmapClassifier::ClassifyBitmap(UBitmap &bmp, MDVector<double> &output_confidences, double conf_thresh, int &class_id, bool &is_classified)
{
    ClassificationTime=0.0;
    clock_t start_frame = clock();

    if(bmp.GetData()==nullptr)
        return false;

    if(ImageColorModel!=bmp.GetColorModel())
    {
        LogMessageEx(RDK_EX_WARNING, __FUNCTION__, std::string("Incorrect image color model. Need "+sntoa(*ImageColorModel)+" got: ")+sntoa(bmp.GetColorModel()));
        return false;
    }

    /// Тут считаем
    ////////////////////////////////////////////////////////////
    /// Здесь место для обработки изображения сетью

    image img = UBitmapToImage(bmp);

    if(img.data==NULL)
    {
        LogMessageEx(RDK_EX_WARNING, __FUNCTION__, std::string("InputImage not converted correctly to darknet image"));
        return false;
    }

    image resized = resize_min(img, Network->w);
    image crop = crop_image(resized, (resized.w - Network->w)/2, (resized.h - Network->h)/2, Network->w, Network->h);

    float *pred = network_predict(Network, crop.data);

    if(Network->hierarchy) hierarchy_predictions(pred, Network->outputs, Network->hierarchy, 0, 1);

    if(TopLayer.outputs!=NumClasses)
    {
        LogMessageEx(RDK_EX_WARNING,__FUNCTION__,"Number of classes is wrong");
        return false;
    }

    output_confidences.Resize(NumClasses);

    int max_id = -1;
    double max_conf = -100;

    for(int k=0; k<NumClasses; k++)
    {
        output_confidences(k) = pred[k];
        if(output_confidences(k)>max_conf)
        {
            max_conf = output_confidences(k);
            max_id = k;
        }
    }

    if(max_conf<conf_thresh)
    {
        is_classified=false;
    }
    else
    {
        is_classified=true;
    }

    class_id = max_id;
    clock_t end_frame = clock();
    ClassificationTime = (double)(end_frame - start_frame) / CLOCKS_PER_SEC;


    return true;
}

}
#endif



