## TDarknetObjectDetector — детектор (YOLO/Darknet)

**Класс**: `TDarknetObjectDetector` (`DarknetObjectDetector`) — детекция объектов с использованием Darknet/YOLO.  
**Регистрация**: `Core/Lib.cpp` → `UploadClass("DarknetObjectDetector", ...)`.  
**Storage-инстансы**: `ClassName = "DarknetObjectDetector"`; параметры: cfg/weights, labels, threshold, NMS.

```mermaid
classDiagram
    UComponent <|-- TDarknetObjectDetector
    class TDarknetObjectDetector {
        +cfgPath : string
        +weightsPath : string
        +labels : list
    }
```

### Входы/выходы
- Вход: `UBitmap` изображение.
- Выход: bounding boxes, классы, scores.

```mermaid
flowchart LR
    img[UBitmap] --> det[TDarknetObjectDetector]
    det --> boxes[Boxes/classes]
```

Пояснение: блок-схема показывает поток данных/сигналов (входы → компонент → выходы).

```mermaid
sequenceDiagram
    participant Cfg as Config
    participant Det as TDarknetObjectDetector
    Cfg->>Det: load cfg/weights
    loop per frame
        Cfg-->>Det: image
        Det-->>Cfg: detections
    end
```

Пояснение: диаграмма последовательности показывает типовой сценарий взаимодействия и порядок вызовов.

---

## TDarknetObjectDetector — Darknet detector

Runs YOLO/Darknet network on images, outputs detections.
