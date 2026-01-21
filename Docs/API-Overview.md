# Обзор API Rdk-DarknetLib

## RU

### Основные классы

#### DarknetLib

Главный класс библиотеки, наследник `ULibrary`.

#### TDarknetObjectDetector

Детектор объектов Darknet.

**Основные свойства:**
- `ConfigFile` - файл конфигурации (.cfg)
- `WeightsFile` - файл весов (.weights)
- `NamesFile` - файл с именами классов
- `InputImage` - входное изображение
- `DetectedObjects` - обнаруженные объекты

#### TDarknetUBitmapClassifier

Классификатор изображений Darknet.

**Основные свойства:**
- `ModelFile` - файл модели
- `InputImage` - входное изображение
- `ClassLabel` - метка класса
- `Confidence` - уверенность классификации

### См. также

- Исходный код: `Libraries/Rdk-DarknetLib/Core/`

---

## EN

### Main Classes

#### DarknetLib

Main library class, inherits from `ULibrary`.

#### TDarknetObjectDetector

Darknet object detector.

**Main Properties:**
- `ConfigFile` - configuration file (.cfg)
- `WeightsFile` - weights file (.weights)
- `NamesFile` - class names file
- `InputImage` - input image
- `DetectedObjects` - detected objects

#### TDarknetUBitmapClassifier

Darknet image classifier.

**Main Properties:**
- `ModelFile` - model file
- `InputImage` - input image
- `ClassLabel` - class label
- `Confidence` - classification confidence

### See Also

- Source code: `Libraries/Rdk-DarknetLib/Core/`
