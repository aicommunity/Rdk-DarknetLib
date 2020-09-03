#ifndef RDK_TDarknetComponentH
#define RDK_TDarknetComponentH

//#include "TPythonIntegrationInclude.h"
//#include "TPythonIntegrationUtil.h"
#include "../../../Rdk/Deploy/Include/rdk.h"
#include "../ThirdParty/darknet/include/darknet.h"

namespace RDK {

class TDarknetComponent: virtual public RDK::UNet
{
public: // ��������
/// ������� �����������

/// ����� �����, ������������ �������� ������, �� ������� ���������� ����
/// ubmRGB24=3 - ������� �����������
/// umbY8=400 - �����-����� �����������
ULProperty<int,TDarknetComponent, ptPubParameter> ImageColorModel;

///���� � ����� ������������
ULProperty<std::string,TDarknetComponent, ptPubParameter> ConfigPath;
///���� � ����� �����
ULProperty<std::string,TDarknetComponent, ptPubParameter> WeightsPath;

protected: // ���������� ���������
UBitmap ProcessedBmp;


bool Initialized;

network *Network;
layer TopLayer;


public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
TDarknetComponent(void);
virtual ~TDarknetComponent(void);
// --------------------------

// --------------------------
// ��������� ������ ���������� ��������
// --------------------------

// --------------------------

// --------------------------
// ������� ������ ���������� ������
// --------------------------
protected:
bool Initialize(void);

virtual void AInit(void);
virtual void AUnInit(void);

// �������������� �������� �� ��������� � ����� �������� �����
virtual bool ADefault(void);
virtual bool ADNDefault(void)=0;

// ������������ ������ ���������� ��������� �������
// ����� ��������� ����������
// ������������� �������� ����� Reset() � ���������� Ready � true
// � ������ �������� ������
virtual bool ABuild(void);
virtual bool ADNBuild(void)=0;

// ����� �������� ����� ��� ������ ��������
virtual bool AReset(void);
virtual bool ADNReset(void)=0;

// ��������� ������ ����� �������
virtual bool ABeforeCalculate(void);

// --------------------------
image UBitmapToImage(const UBitmap& ub);


};


}

#endif



