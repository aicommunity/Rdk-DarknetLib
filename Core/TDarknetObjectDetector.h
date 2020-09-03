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
public: // Свойства


/// Количество классов объектов (какой размер будет у вектора)
ULProperty<int,TDarknetObjectDetector, ptPubParameter> NumClasses;

/// Порог объектности, выше которого обнаружения считаются валидными (objectness)
ULProperty<float,TDarknetObjectDetector, ptPubParameter> ObjectnessThreshold;

///Включить фильтрацию по целевым классам
ULProperty<bool,TDarknetObjectDetector, ptPubParameter> FilterClassesList;

///Список
ULProperty<std::vector<int>,TDarknetObjectDetector, ptPubParameter> ClassesList;

///Тип инициализации: 2 - YOLOV2
///                   3 - YOLOV3
//ULProperty<int,TDarknetObjectDetector, ptPubParameter> InitializationTypeYOLO;


///Путь к модели Йолы
//ULProperty<std::string,TDarknetObjectDetector, ptPubParameter> ModelPathYOLO;
///Путь к файлу с якорями (оставить пустым если используем стандарт)
//ULProperty<std::string,TDarknetObjectDetector, ptPubParameter> AnchorsPathYOLO;
///Путь к файлу с перечнем классов для используемой сети
//ULProperty<std::string,TDarknetObjectDetector, ptPubParameter> ClassesPathYOLO;

///Загружать список классов из соответствующего файла
//ULProperty<bool,TDarknetObjectDetector, ptPubParameter> LoadTargetClassesYOLO;
///Список замен классов (изменить список классов в файле ClassesPathYOLO на свои имена)
///ВНИМАНИЕ!!! Число классов должно соответствовать числу классов в ClassesPathYOLO
//ULProperty<std::vector<std::string>,TDarknetObjectDetector, ptPubParameter> ChangeClassesYOLO;

///Замена классов по значениям
///ULProperty<std::map<int, int>,TDarknetObjectDetector, ptPubParameter> ClassIndicesExchange;


/// Выходная матрица с классами объектов
//UPropertyOutputData<std::vector<int>,TDarknetObjectDetector, ptPubOutput> OutputClasses;



protected: // Переменные состояния


UBitmap Canvas;

std::string PythonScriptFileName;

int NumTargetClassesYOLO;
int NumChangeClassesYOLO;

std::vector<std::string> ClassedList;



public: // Методы
// --------------------------
// Конструкторы и деструкторы
// --------------------------
TDarknetObjectDetector(void);
virtual ~TDarknetObjectDetector(void);
// --------------------------

// ---------------------
// Методы управления параметрами
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
// Методы управления переменными состояния
// ---------------------
// ---------------------

// --------------------------
// Системные методы управления объектом
// --------------------------
// Выделяет память для новой чистой копии объекта этого класса
virtual TDarknetObjectDetector* New(void);
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

bool Detect(UBitmap &bmp, MDMatrix<double> &output_rects, MDMatrix<int> &output_classes, MDMatrix<double> &reliabilities);

};


}

#endif



