#define NO_IMPORT_ARRAY

#ifndef RDK_TDarknetObjectDetectorCPP
#define RDK_TDarknetObjectDetectorCPP

#include "TDarknetObjectDetector.h"
#include <iostream>

namespace RDK {
/*
#if (PY_VERSION_HEX >= 0x03000000)
    void *init_py_pyubclsfr() {
#else
    void init_py_pyubclsfr(){
#endif
        if(Py_IsInitialized())
            return NUMPY_IMPORT_ARRAY_RETVAL;
        Py_Initialize();

        import_array();
        np::initialize();
        return NUMPY_IMPORT_ARRAY_RETVAL;
    }*/

// Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------  //DetectionClass("DetectionClass",this),
TDarknetObjectDetector::TDarknetObjectDetector(void)
://Initialized(false),
  //ModelPathYOLO("ModelPathYOLO",this),
  //AnchorsPathYOLO("AnchorsPathYOLO",this),
  //ClassesPathYOLO("ClassesPathYOLO",this),
  ObjectnessThreshold("ObjectnessThreshold",this),

  FilterClassesList("FilterClassesList",this),
  //LoadTargetClassesYOLO("LoadTargetClassesYOLO",this)
  //OutputConfidences("OutputConfidences", this)
  ClassesList("ClassesList",this),
  NumClasses("NumClasses",this)
{
    /*AddLookupProperty("PythonScriptPath",ptPubParameter, new UVProperty<std::string,TDarknetObjectDetector>(this,
                 &TDarknetObjectDetector::SetPythonClassifierScriptPath,&TDarknetObjectDetector::GetPythonClassifierScriptPath));*/

    /*AddLookupProperty("NumTargetClassesYOLO",ptPubParameter, new UVProperty<int,TDarknetObjectDetector>(this,
                 &TDarknetObjectDetector::SetNumTargetClassesYOLO,&TDarknetObjectDetector::GetNumTargetClassesYOLO));

    AddLookupProperty("NumChangeClassesYOLO",ptPubParameter, new UVProperty<int,TDarknetObjectDetector>(this,
                 &TDarknetObjectDetector::SetNumChangeClassesYOLO,&TDarknetObjectDetector::GetNumChangeClassesYOLO));
*/
}

/*bool TDarknetObjectDetector::SetPythonClassifierScriptPath(const std::string& path)
{
    PythonScriptFileName = path;
    Initialized=false;
    return true;
}
const std::string & TDarknetObjectDetector::GetPythonClassifierScriptPath(void) const
{
    return PythonScriptFileName;
}
*/
/*
bool TDarknetObjectDetector::SetNumTargetClassesYOLO(const int& num)
{
    NumTargetClassesYOLO = num;
    TargetClassesYOLO->resize(num);
    return true;
}
const int& TDarknetObjectDetector::GetNumTargetClassesYOLO(void) const
{
    return NumTargetClassesYOLO;
}

bool TDarknetObjectDetector::SetNumChangeClassesYOLO(const int& num)
{
    NumChangeClassesYOLO = num;
    ChangeClassesYOLO->resize(num);
    return true;
}
const int& TDarknetObjectDetector::GetNumChangeClassesYOLO(void) const
{
    return NumChangeClassesYOLO;
}
*/

TDarknetObjectDetector::~TDarknetObjectDetector(void)
{
    //В примере очистки нет, предполагаю, что это ссылка на полноценную
    //структуру данных где-то внутри, которая уничтожается в другом месте
    /*if(Network)
        delete Network;*/
}
// --------------------------


// ---------------------
// Методы управления параметрами
// ---------------------
// ---------------------

// ---------------------
// Методы управления переменными состояния
// ---------------------
// ---------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
TDarknetObjectDetector* TDarknetObjectDetector::New(void)
{
 return new TDarknetObjectDetector;
}
// --------------------------



// --------------------------
// Скрытые методы управления счетом
// --------------------------


// Восстановление настроек по умолчанию и сброс процесса счета
bool TDarknetObjectDetector::ADNDefault(void)
{
 ObjectnessThreshold = 0.0f;
 FilterClassesList=false;
 return true;
}
// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
bool TDarknetObjectDetector::ADNBuild(void)
{
 return true;
}

// Сброс процесса счета без потери настроек
bool TDarknetObjectDetector::ADNReset(void)
{
 //Initialized = false;
 return true;
}

// Выполняет расчет этого объекта

bool TDarknetObjectDetector::ADNCalculate(void)
{
    if(!InputImage.IsConnected())
        return true;

    ProcessedBmp = *InputImage;

    if(ProcessedBmp.GetData()==nullptr)
        return true;

    if(!Detect(ProcessedBmp, *OutputRects, *OutputClasses, *OutputReliability))
        return true;

    OutputObjects->Resize(OutputRects->GetRows(), 6);
    for(int i=0;i<OutputRects->GetRows();i++)
    {
        double wm = (*UseRelativeCoords)?(InputImage->GetWidth()):(1);
        double hm = (*UseRelativeCoords)?(InputImage->GetHeight()):(1);

        (*OutputObjects)(i,0) = (int)((*OutputRects)(i,0)*wm);
        (*OutputObjects)(i,1) = (int)((*OutputRects)(i,1)*hm);
        (*OutputObjects)(i,2) = (int)((*OutputRects)(i,2)*wm);
        (*OutputObjects)(i,3) = (int)((*OutputRects)(i,3)*hm);
        (*OutputObjects)(i,4) = (*OutputReliability)(i,0);
        (*OutputObjects)(i,5) = (*OutputClasses)(i,0);
    }

    if(UseDebugImage)
    {
        DebugImage->SetColorModel(ubmRGB24,false);
        InputImage->ConvertTo(*DebugImage);

        Graph.SetCanvas(DebugImage);

        UAFont *class_font=GetFont("Tahoma",20);

        for(int i=0; i<OutputRects->GetRows(); i++)
        {
            int xmin, ymin, xmax, ymax;

            xmin = (int)((*OutputObjects)(i,0));
            ymin = (int)((*OutputObjects)(i,1));
            xmax = (int)((*OutputObjects)(i,2));
            ymax = (int)((*OutputObjects)(i,3));

            double conf = (*OutputReliability)(i,0);
            int cls = (*OutputClasses)(i,0);

            Graph.SetPenColor(0x00FF00);
            Graph.SetPenWidth(3);
            Graph.Rect(xmin, ymin, xmax, ymax);

            std::stringstream ss;
            ss<<cls<<"["<<conf<<"]";

            if(class_font)
            {
                Graph.SetFont(class_font);
                Graph.Text(ss.str(),xmin, ymax+3);
            }
        }
    }
    return true;
}
// --------------------------
bool TDarknetObjectDetector::Detect(UBitmap &bmp, MDMatrix<double> &output_rects, MDMatrix<int> &output_classes, MDMatrix<double> &reliabilities)
{
    //TODO доработать детекцию
    image img = UBitmapToImage(bmp);
    if(img.data==nullptr)
    {
        LogMessageEx(RDK_EX_WARNING, __FUNCTION__, std::string("InputImage not converted correctly to darknet image"));
        return false;
    }

    int nboxes = 0;
    image sized = resize_image(img, Network->w, Network->h);
    float *X = sized.data;

    network_predict(Network, X);
    detection *dets = get_network_boxes(Network, sized.w, sized.h, *ConfidenceThreshold, 0.5, 0, 0, &nboxes);


    int t = TopLayer.side*TopLayer.side*TopLayer.n;
    do_nms_obj(dets, nboxes, TopLayer.classes, NMSthreshold);

    std::vector<std::vector<double> > result;

    int num_detections = 0;
    for(int i=0; i<nboxes; i++)
    {
        detection &d = dets[i];
        if(d.objectness<ObjectnessThreshold)
            continue;

        int cmax = -1;
        float probmax=-1.0;
        for(int ci=0; ci<d.classes; ci++)
        {
            if(d.prob[ci]>probmax)
            {
                probmax = d.prob[ci];
                cmax = ci;
            }
        }

        if(FilterClassesList)
        {
           if(ClassesList->size()>0)
           {
               bool skip=true;
               for(int ci=0; ci<ClassesList->size(); ci++)
               {
                   if((*ClassesList)[ci]==cmax)
                   {
                       skip=false;
                   }
               }
               if(skip)
                   continue;
           }
        }

        double xmin = d.bbox.x-d.bbox.w/2;
        double xmax = d.bbox.x+d.bbox.w/2;
        double ymin = d.bbox.y-d.bbox.h/2;
        double ymax = d.bbox.y+d.bbox.h/2;

        num_detections++;
        std::vector<double> res;
        res.resize(6);
        res[0] = xmin;
        res[1] = ymin;
        res[2] = xmax;
        res[3] = ymax;

        res[4] = probmax;
        res[5] = cmax;

        result.push_back(res);

    }

    free_detections(dets, nboxes);
    free_image(img);
    free_image(sized);


    output_rects.Resize(num_detections,4);
    output_classes.Resize(num_detections,1);
    reliabilities.Resize(num_detections,1);

    for(int y=0; y<num_detections; y++)
    {
        output_rects(y,0) =  result[y][0];
        output_rects(y,1) =  result[y][1];
        output_rects(y,2) =  result[y][2];
        output_rects(y,3) =  result[y][3];

        reliabilities(y,0)  = result[y][4];
        output_classes(y,0) = result[y][5];
    }

    return true;
}


}
#endif



