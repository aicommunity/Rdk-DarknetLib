#ifndef RDK_TDarknetComponentH
#define RDK_TDarknetComponentH

//#include "TPythonIntegrationInclude.h"
//#include "TPythonIntegrationUtil.h"
#include "../../../Rdk/Deploy/Include/rdk.h"
#include "../ThirdParty/darknet/include/darknet.h"

namespace RDK {

class TDarknetComponent: virtual public RDK::UNet
{
public: // Свойства
/// Входное изображение

/// Целое число, определяющее цветовую модель, на которую рассчитана сеть
/// ubmRGB24=3 - цветное изображение
/// umbY8=400 - черно-белое изображение
ULProperty<int,TDarknetComponent, ptPubParameter> ImageColorModel;

///Путь к файлу конфигурации
ULProperty<std::string,TDarknetComponent, ptPubParameter> ConfigPath;
///Путь к файлу весов
ULProperty<std::string,TDarknetComponent, ptPubParameter> WeightsPath;

protected: // Переменные состояния
UBitmap ProcessedBmp;


bool Initialized;

network *Network;
layer TopLayer;


public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
TDarknetComponent(void);
virtual ~TDarknetComponent(void);
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------

// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
protected:
bool Initialize(void);

virtual void AInit(void);
virtual void AUnInit(void);

// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool ADefault(void);
virtual bool ADNDefault(void)=0;

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
virtual bool ABuild(void);
virtual bool ADNBuild(void)=0;

// Сброс процесса счета без потери настроек
virtual bool AReset(void);
virtual bool ADNReset(void)=0;

// Выполняет расчет этого объекта
virtual bool ABeforeCalculate(void);

// --------------------------
image UBitmapToImage(const UBitmap& ub);


};


}

#endif



