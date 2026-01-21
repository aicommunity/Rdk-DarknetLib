# Rdk-DarknetLib — Component Catalog

Компоненты из `Core/Lib.cpp` (регистрация под `RDK_USE_DARKNET`) с кратким назначением.

## Detectors
- **TDarknetObjectDetector** / `DarknetObjectDetector` — детекция объектов (YOLO/Darknet); вход: UBitmap/изображение; выход: bounding boxes/классы.

## Classifiers
- **TDarknetUBitmapClassifier** / `DarknetUBitmapClassifier` — классификация bitmap через Darknet; вход: изображение; выход: метка/скор.

**Приоритет описания:** загрузка cfg/weights, подготовка входов (UBitmap), формат выходов и типовые сценарии использования. См. `Docs/Components/DarknetComponents.md` и детальные файлы: [`TDarknetObjectDetector`](Components/TDarknetObjectDetector.md), [`TDarknetUBitmapClassifier`](Components/TDarknetUBitmapClassifier.md).
