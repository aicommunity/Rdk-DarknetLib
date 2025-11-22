#ifndef Rdk_UDarknetLib_CPP
#define Rdk_UDarknetLib_CPP

#include "Lib.h"

namespace RDK {

UDarknetLib DarknetLib;



// --------------------------
// Конструкторы и деструкторы
// --------------------------
UDarknetLib::UDarknetLib(void)
 : RDK::ULibrary("DarknetLib","1.0")
{
}
// --------------------------

// --------------------------
// Методы заполенения бибилиотеки
// --------------------------
// Заполняет массив ClassSamples готовыми экземплярами образцов и их именами.
// Не требуется предварительная очистка массива и уборка памяти.
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


