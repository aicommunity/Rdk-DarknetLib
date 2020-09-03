#ifndef RDK_TDarknetObjectDetectorH
#define RDK_TDarknetObjectDetectorH

//#include "TPythonIntegrationInclude.h"
//#include "TPythonIntegrationUtil.h"

#include "../../Rdk-CRLib/Core/UDetectorBase.h"
#include "TDarknetComponent.h"
namespace RDK {

#define YOLOV2_INITTYPE 2
#define YOLOV3_INITTYPE 3

class TDarknetObjectDetector: public TDarknetComponent, public UDetectorBase
{
public: // ��������


/// ���������� ������� �������� (����� ������ ����� � �������)
ULProperty<int,TDarknetObjectDetector, ptPubParameter> NumClasses;

/// ����� �����������, ���� �������� ����������� ��������� ��������� (objectness)
ULProperty<float,TDarknetObjectDetector, ptPubParameter> ObjectnessThreshold;

///�������� ���������� �� ������� �������
ULProperty<bool,TDarknetObjectDetector, ptPubParameter> FilterClassesList;

///������
ULProperty<std::vector<int>,TDarknetObjectDetector, ptPubParameter> ClassesList;

///��� �������������: 2 - YOLOV2
///                   3 - YOLOV3
//ULProperty<int,TDarknetObjectDetector, ptPubParameter> InitializationTypeYOLO;


///���� � ������ ����
//ULProperty<std::string,TDarknetObjectDetector, ptPubParameter> ModelPathYOLO;
///���� � ����� � ������� (�������� ������ ���� ���������� ��������)
//ULProperty<std::string,TDarknetObjectDetector, ptPubParameter> AnchorsPathYOLO;
///���� � ����� � �������� ������� ��� ������������ ����
//ULProperty<std::string,TDarknetObjectDetector, ptPubParameter> ClassesPathYOLO;

///��������� ������ ������� �� ���������������� �����
//ULProperty<bool,TDarknetObjectDetector, ptPubParameter> LoadTargetClassesYOLO;
///������ ����� ������� (�������� ������ ������� � ����� ClassesPathYOLO �� ���� �����)
///��������!!! ����� ������� ������ ��������������� ����� ������� � ClassesPathYOLO
//ULProperty<std::vector<std::string>,TDarknetObjectDetector, ptPubParameter> ChangeClassesYOLO;

///������ ������� �� ���������
///ULProperty<std::map<int, int>,TDarknetObjectDetector, ptPubParameter> ClassIndicesExchange;


/// �������� ������� � �������� ��������
//UPropertyOutputData<std::vector<int>,TDarknetObjectDetector, ptPubOutput> OutputClasses;



protected: // ���������� ���������


UBitmap Canvas;

std::string PythonScriptFileName;

int NumTargetClassesYOLO;
int NumChangeClassesYOLO;

std::vector<std::string> ClassedList;



public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
TDarknetObjectDetector(void);
virtual ~TDarknetObjectDetector(void);
// --------------------------

// ---------------------
// ������ ���������� �����������
// ---------------------
// ---------------------

//bool SetPythonClassifierScriptPath(const std::string& path);
//const std::string &GetPythonClassifierScriptPath(void) const;

/*
bool SetNumTargetClassesYOLO(const int& num);
const int& GetNumTargetClassesYOLO(void) const;

bool SetNumChangeClassesYOLO(const int& num);
const int& GetNumChangeClassesYOLO(void) const;
*/
// ---------------------
// ������ ���������� ����������� ���������
// ---------------------
// ---------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------
// �������� ������ ��� ����� ������ ����� ������� ����� ������
virtual TDarknetObjectDetector* New(void);
// --------------------------


// --------------------------
// ������� ������ ���������� ������
// --------------------------
protected:

// �������������� �������� �� ��������� � ����� �������� �����
virtual bool ADNDefault(void);

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
virtual bool ADNBuild(void);

// ����� �������� ����� ��� ������ ��������
virtual bool ADNReset(void);


// --------------------------

bool Detect(UBitmap &bmp, MDMatrix<double> &output_rects, MDMatrix<int> &output_classes, MDMatrix<double> &reliabilities);

};


}

#endif



