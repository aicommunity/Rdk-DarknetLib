#ifndef Rdk_UDarknetLib_H
#define Rdk_UDarknetLib_H

#include "../../../Rdk/Deploy/Include/rdk.h"
//open file here

#ifdef RDK_USE_DARKNET
#include "TDarknetObjectDetector.h"
#include "TDarknetUBitmapClassifier.h"
#endif

namespace RDK {

class RDK_LIB_TYPE UDarknetLib: public RDK::ULibrary
{
public: // ������
// --------------------------
// ������������ � �����������
// --------------------------
UDarknetLib(void);
// --------------------------

// --------------------------
// ������ ����������� �����������
// --------------------------
// ��������� ������ ClassSamples �������� ������������ �������� � �� �������.
// �� ��������� ��������������� ������� ������� � ������ ������.
virtual void CreateClassSamples(RDK::UStorage *storage);
// --------------------------
};

extern RDK_LIB_TYPE UDarknetLib DarknetLib;

}

#endif


