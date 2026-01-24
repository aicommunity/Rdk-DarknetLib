# Rdk-DarknetLib - Документация

## RU

### Назначение

**Rdk-DarknetLib** предоставляет интеграцию с Darknet для детекции объектов и классификации изображений.

### Краткий обзор

Библиотека включает компоненты для:
- Детекции объектов с использованием Darknet
- Классификации изображений

### Быстрый старт

#### Детекция объектов с Darknet

```cpp
// Создание детектора
auto detector = storage->CreateComponent<TDarknetObjectDetector>("Detector");
detector->ConfigPath = "yolo.cfg";
detector->WeightsPath = "yolo.weights";
detector->InputImage.AttachTo(&source->OutputImage);
detector->Build();
detector->Calculate();
auto detections = detector->Detections();
```

### Связь с корневой документацией

Для обзорной информации см. корневую документацию проекта:
- `Docs/Libraries/Rdk-DarknetLib.md` - обзор библиотеки (в корневом репозитории)

### Детальная документация

- [Architecture.md](Architecture.md) - архитектура библиотеки
- [Usage-Examples.md](Usage-Examples.md) - примеры использования
- [API-Overview.md](API-Overview.md) - обзор API
- [Component-Catalog.md](Component-Catalog.md) - каталог компонентов

---

## EN

### Purpose

**Rdk-DarknetLib** provides integration with Darknet for object detection and image classification.

### Brief Overview

The library includes components for:
- Object detection using Darknet
- Image classification

### Link to Root Documentation

For overview information see root project documentation:
- `Docs/Libraries/Rdk-DarknetLib.md` - library overview (in root repository)

### Detailed Documentation

- [Architecture.md](Architecture.md) - library architecture
- [Usage-Examples.md](Usage-Examples.md) - usage examples
- [API-Overview.md](API-Overview.md) - API overview
- [Component-Catalog.md](Component-Catalog.md) - component catalog
