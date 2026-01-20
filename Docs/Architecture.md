# Архитектура Rdk-DarknetLib

## RU

### Обзор

Rdk-DarknetLib предоставляет компонентный интерфейс для работы с Darknet.

### Структура библиотеки

```mermaid
flowchart TB
    TDarknetObjectDetector[TDarknetObjectDetector<br/>Детектор объектов]
    TDarknetClassifier[TDarknetUBitmapClassifier<br/>Классификатор]
    DarknetLib[Darknet Library]
    
    TDarknetObjectDetector --> DarknetLib
    TDarknetClassifier --> DarknetLib
```

### Основные модули

#### Детекция объектов

- **TDarknetObjectDetector** - детектор объектов на базе Darknet

#### Классификация

- **TDarknetUBitmapClassifier** - классификатор изображений на базе Darknet

### Зависимости

- `rdk.static.qt` - ядро Rdk
- Darknet - библиотека Darknet

### См. также

- [Usage-Examples.md](Usage-Examples.md) - примеры использования
- [API-Overview.md](API-Overview.md) - обзор API

---

## EN

### Overview

Rdk-DarknetLib provides a component interface for working with Darknet.

### Library Structure

### Main Modules

#### Object Detection

- **TDarknetObjectDetector** - Darknet-based object detector

#### Classification

- **TDarknetUBitmapClassifier** - Darknet-based image classifier

### Dependencies

- `rdk.static.qt` - Rdk core
- Darknet - Darknet library

### See Also

- [Usage-Examples.md](Usage-Examples.md) - usage examples
- [API-Overview.md](API-Overview.md) - API overview
