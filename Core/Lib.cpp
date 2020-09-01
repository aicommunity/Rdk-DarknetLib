#ifndef Rdk_UDarknetLib_CPP
#define Rdk_UDarknetLib_CPP

#include "Lib.h"

namespace RDK {

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


