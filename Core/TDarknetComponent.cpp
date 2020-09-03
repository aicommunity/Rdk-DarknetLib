#ifndef RDK_TDarknetComponentCPP
#define RDK_TDarknetComponentCPP

#include "TDarknetComponent.h"
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

namespace RDK {

bool RdkCvResize(const UBitmap &source, UBitmap &dest, int new_width, int new_height)
{
 if(source.GetColorModel() != ubmY8 || source.GetColorModel() != ubmRGB24)
  return false;

 if(new_width <0 || new_height <0)
  return false;

 if(new_width ==0 || new_height == 0)
 {
  dest.SetRes(new_width, new_height, source.GetColorModel());
  return true;
 }

 dest.SetRes(new_width, new_height, source.GetColorModel());

 if(source.GetColorModel() == ubmRGB24)
 {
  cv::Mat cv_source(source.GetHeight(),source.GetWidth(),CV_8UC1,source.GetData());
  cv::Mat cv_dest(dest.GetHeight(),dest.GetWidth(),CV_8UC1,dest.GetData());
  cv::resize(cv_source, cv_dest, cv::Size(new_width, new_height), 0,0,cv::INTER_CUBIC);
 }
 else
 if(source.GetColorModel() == ubmY8)
 {
  cv::Mat cv_source(source.GetHeight(),source.GetWidth(),CV_8UC3,source.GetData());
  cv::Mat cv_dest(dest.GetHeight(),dest.GetWidth(),CV_8UC3,dest.GetData());
  cv::resize(cv_source, cv_dest, cv::Size(new_width, new_height), 0,0,cv::INTER_CUBIC);
 }
 return true;
}

// Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------  //DetectionClass("DetectionClass",this),
TDarknetComponent::TDarknetComponent(void)
: ImageColorModel("ImageColorModel",this),
  ConfigPath("ConfigPath",this),
  WeightsPath("WeightsPath",this)
{
}

TDarknetComponent::~TDarknetComponent(void)
{
    //free_network(Network);
}
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------

// --------------------------


void TDarknetComponent::AInit(void)
{
    if(!Initialized)
    {
       if(!Initialize())
           return;
    }
}

void TDarknetComponent::AUnInit(void)
{
}
// --------------------------
// Скрытые методы управления счетом
// --------------------------
bool TDarknetComponent::Initialize(void)
{
    if(ConfigPath->size()==0 || WeightsPath->size()==0)
    {
        LogMessageEx(RDK_EX_WARNING, __FUNCTION__, std::string("TDarknetUBitmapClassifier error: ConfigPath or WeightsPath is empty!"));
        return false;
    }
    try {
        Network = load_network(const_cast<char*>(ConfigPath->c_str()), const_cast<char*>(WeightsPath->c_str()), 0);
        TopLayer = Network->layers[Network->n-1];

        /*if(Network)
            TopLayer = &(Network->layers[Network->n-1]);*/
        /*set_batch_network(Network, 1);*/
    } catch (...) {
        LogMessageEx(RDK_EX_WARNING, __FUNCTION__, std::string("TDarknetUBitmapClassifier error: Unhandled exception"));
        return false;
    }

    if(Network)
    {
        Initialized=true;
        return true;
    }
    else
    {
        Initialized=false;
        return false;
    }

}


// Восстановление настроек по умолчанию и сброс процесса счета
bool TDarknetComponent::ADefault(void)
{
    return ADNReset();
}

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool TDarknetComponent::ABuild(void)
{
    return ADNBuild();
}

// Сброс процесса счета без потери настроек
bool TDarknetComponent::AReset(void)
{
    return ADNReset();
}

// Выполняет расчет этого объекта
bool TDarknetComponent::ACalculate(void)
{
    return ADNCalculate();
}

image TDarknetComponent::UBitmapToImage(const UBitmap& ub)
{
    int h = ub.GetHeight();
    int w = ub.GetWidth();
    int cm = ub.GetColorModel();

    int step = ub.GetLineByteLength();
    int c = ub.GetPixelByteLength();

    if(cm==ubmRGB24)
    {
        image im = make_image(w, h, c);
        unsigned char *data = (unsigned char *)ub.GetData();
        for(int i = 0; i < h; ++i){
            for(int k= 0; k < c; ++k){
                for(int j = 0; j < w; ++j){
                    im.data[k*w*h + i*w + j] = data[i*step + j*c + k]/255.;
                }
            }
        }
        return im;

    }
    else if(cm==ubmY8)
    {
        return image();
    }
    else
    {
        return image();
    }
}


}
#endif



