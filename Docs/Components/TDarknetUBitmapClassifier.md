## TDarknetUBitmapClassifier — классификатор Darknet

**Класс**: `TDarknetUBitmapClassifier` (`DarknetUBitmapClassifier`) — классификация bitmap через Darknet.  
**Регистрация**: `Core/Lib.cpp` → `UploadClass("DarknetUBitmapClassifier", ...)`.  
**Storage-инстансы**: `ClassName = "DarknetUBitmapClassifier"`; параметры: cfg/weights, labels.

```mermaid
classDiagram
    UComponent <|-- TDarknetUBitmapClassifier
```

### Входы/выходы
- Вход: `UBitmap`.
- Выход: класс/скор.

```mermaid
flowchart LR
    img[UBitmap] --> cls[TDarknetUBitmapClassifier]
    cls --> label[Class/score]
```

Пояснение: блок-схема показывает поток данных/сигналов (входы → компонент → выходы).

```mermaid
sequenceDiagram
    participant Cfg as Config
    participant Cls as TDarknetUBitmapClassifier
    Cfg->>Cls: load cfg/weights
    loop per image
        Cfg-->>Cls: bitmap
        Cls-->>Cfg: class/score
    end
```

Пояснение: диаграмма последовательности показывает типовой сценарий взаимодействия и порядок вызовов.

---

## TDarknetUBitmapClassifier — Darknet classifier

Classifies bitmaps using Darknet model, returning label/score.
