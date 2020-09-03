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

// ������
// --------------------------
// ������������ � �����������
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
    //� ������� ������� ���, �����������, ��� ��� ������ �� �����������
    //��������� ������ ���-�� ������, ������� ������������ � ������ �����
    /*if(Network)
        delete Network;*/
}
// --------------------------


// ---------------------
// ������ ���������� �����������
// ---------------------
// ---------------------

// ---------------------
// ������ ���������� ����������� ���������
// ---------------------
// ---------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
TDarknetObjectDetector* TDarknetObjectDetector::New(void)
{
 return new TDarknetObjectDetector;
}
// --------------------------



// --------------------------
// ������� ������ ���������� ������
// --------------------------


// �������������� �������� �� ��������� � ����� �������� �����
bool TDarknetObjectDetector::ADNDefault(void)
{
 ObjectnessThreshold = 0.0f;
 FilterClassesList=false;
 return true;
}
// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
bool TDarknetObjectDetector::ADNBuild(void)
{
 return true;
}

// ����� �������� ����� ��� ������ ��������
bool TDarknetObjectDetector::ADNReset(void)
{
 //Initialized = false;
 return true;
}

// ��������� ������ ����� �������


// --------------------------
bool TDarknetObjectDetector::Detect(UBitmap &bmp, MDMatrix<double> &output_rects, MDMatrix<int> &output_classes, MDMatrix<double> &reliabilities)
{
    //TODO ���������� ��������
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



