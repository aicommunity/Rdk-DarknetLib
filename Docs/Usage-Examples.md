# Примеры использования Rdk-DarknetLib

## RU

### Пример 1: Детекция объектов

```cpp
// Создание детектора объектов Darknet
auto detector = storage->CreateComponent<TDarknetObjectDetector>();
detector->ConfigFile = "yolo.cfg";
detector->WeightsFile = "yolo.weights";
detector->NamesFile = "coco.names";
detector->Build();

// Детекция объектов
detector->InputImage = inputImage;
detector->Calculate();
auto objects = detector->DetectedObjects;
```

### Пример 2: Классификация изображений

```cpp
// Создание классификатора Darknet
auto classifier = storage->CreateComponent<TDarknetUBitmapClassifier>();
classifier->ModelFile = "darknet_model.weights";
classifier->Build();

// Классификация
classifier->InputImage = inputImage;
classifier->Calculate();
auto classLabel = classifier->ClassLabel;
```

---

## EN

### Example 1: Object Detection

```cpp
// Creating Darknet object detector
auto detector = storage->CreateComponent<TDarknetObjectDetector>();
detector->ConfigFile = "yolo.cfg";
detector->WeightsFile = "yolo.weights";
detector->NamesFile = "coco.names";
detector->Build();

// Object detection
detector->InputImage = inputImage;
detector->Calculate();
auto objects = detector->DetectedObjects;
```

### Example 2: Image Classification

```cpp
// Creating Darknet classifier
auto classifier = storage->CreateComponent<TDarknetUBitmapClassifier>();
classifier->ModelFile = "darknet_model.weights";
classifier->Build();

// Classification
classifier->InputImage = inputImage;
classifier->Calculate();
auto classLabel = classifier->ClassLabel;
```
