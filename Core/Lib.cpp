#ifndef Rdk_@UPPUDarknetLib_CPP
#define Rdk_@UPPUDarknetLib_CPP

#include "UDarknetLib.h"

namespace Rdk {

UDarknetLib DarknetLib;



// --------------------------
// ������������ � �����������
// --------------------------
UDarknetLib::UDarknetLib(void)
 : RDK::ULibrary("DarknetLib","1.0")
{
}
// --------------------------

// --------------------------
// ������ ����������� �����������
// --------------------------
// ��������� ������ ClassSamples �������� ������������ �������� � �� �������.
// �� ��������� ��������������� ������� ������� � ������ ������.
void UDarknetLib::CreateClassSamples(RDK::UStorage *storage)
{

#ifdef RDK_USE_DARKNET
 UploadClass<TDarknetObjectDetector>("TDarknetObjectDetector","DarknetObjectDetector");
 UploadClass<TDarknetUBitmapClassifier>("TDarknetUBitmapClassifier","DarknetUBitmapClassifier");
#endif
}
// --------------------------

}

#endif


