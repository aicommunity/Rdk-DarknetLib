#ifndef RDK_TDarknetUBitmapClassifierH
#define RDK_TDarknetUBitmapClassifierH

//#include "TPythonIntegrationInclude.h"
//#include "TPythonIntegrationUtil.h"

#include "../../Rdk-CRLib/Core/UClassifierBase.h"
#include "TDarknetComponent.h"

#define CLASS_UNDEFINED -2
#define CLASS_LOWQUAL -3

namespace RDK {

class TDarknetUBitmapClassifier: public UClassifierBase, public TDarknetComponent
{
public: // Свойства

protected: // Переменные состояния




public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
TDarknetUBitmapClassifier(void);
virtual ~TDarknetUBitmapClassifier(void);
// --------------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
virtual TDarknetUBitmapClassifier* New(void);
// --------------------------

// --------------------------
// Скрытые методы управления счетом
// --------------------------
protected:

// Восстановление настроек по умолчанию и сброс процесса счета
virtual bool ADNDefault(void);

// Обеспечивает сборку внутренней структуры объекта
// после настройки параметров
// Автоматически вызывает метод Reset() и выставляет Ready в true
// в случае успешной сборки
virtual bool ADNBuild(void);

// Сброс процесса счета без потери настроек
virtual bool ADNReset(void);


// --------------------------

/// Обрабатывает одно изображение
virtual bool ClassifyBitmap(UBitmap &bmp, MDVector<double> &output_confidences, double conf_thresh, int &class_id, bool &is_classified);

};


}

#endif



