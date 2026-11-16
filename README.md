# Система синхронного перевода для созвонов (Elor C++)

**Учебный репозиторий по дисциплине:** «Жизненный цикл разработки программного обеспечения» (ЖЦРПО)  
**Автор:** Бышкало Владислав Павлович, студент группы 450503  
**Заказчик (ролевая игра):** Равковский Андрей Васильевич, студент группы 450503  
**Специальность:** 6-05-0611-05 «Компьютерная инженерия» (БГУИР, ФКСиС, кафедра ЭВМ)  
**Основной репозиторий исходного кода C++:** [https://github.com/vodopad-ik/Elor](https://github.com/vodopad-ik/Elor)

---

## Навигация по лабораторным работам

### Лабораторная работа № 3 — Бизнес-требования (SRS)
- **Спецификация требований к ПО (SRS v0.2):** [`srs/srs.md`](srs/srs.md)
- **Диаграммы SysML v2 и GUI-мокапы:** [`srs/img/`](srs/img/)
- **Обсуждение и рецензирование с Заказчиком:** [Pull Request #1](https://github.com/vodopad-ik/SDLC/pull/1) (ветка `feature/lab3-srs`)

### Лабораторная работа № 4 — Системные требования (SDD, ADR, Планирование)
- **Описание архитектурного дизайна (SDD):** [`sdd/sdd.md`](sdd/sdd.md) и схема архитектуры [`sdd/img/architecture.png`](sdd/img/architecture.png)
- **Реестр архитектурных решений (ADR 0001–0006):** [`adr/`](adr/)
  - [`0001-target-os-windows.md`](adr/0001-target-os-windows.md) — выбор целевой ОС Windows 11 x64
  - [`0002-engine-as-separate-process.md`](adr/0002-engine-as-separate-process.md) — двухпроцессная модель (`elor-engine` + `elor-app`)
  - [`0003-cpp-qt-stack.md`](adr/0003-cpp-qt-stack.md) — стек C++23 и Qt 6.8 LTS (QML)
  - [`0004-cloud-ai-gemini-first.md`](adr/0004-cloud-ai-gemini-first.md) — облачный потоковый перевод (Gemini Live API)
  - [`0005-turn-detection-and-never-erase.md`](adr/0005-turn-detection-and-never-erase.md) — Silero VAD на ONNX Runtime и инвариант Never-Erase
  - [`0006-screen-capture-and-multimodal-vision.md`](adr/0006-screen-capture-and-multimodal-vision.md) — скринкапчур DWM и мультимодальный контекст
- **Планы разработки (`P0 → P1 → P2`), риски, DoR/DoD и дорожная карта:** [`docs/ROADMAP.md`](docs/ROADMAP.md) и диаграмма Ганта [`docs/img/roadmap.png`](docs/img/roadmap.png)
- **Полная переписка с Заказчиком (Раунд 1 и Раунд 2):** [`docs/NEGOTIATIONS.md`](docs/NEGOTIATIONS.md)
- **Обсуждение раундов согласования в GitHub:** [Pull Request #2](https://github.com/vodopad-ik/SDLC/pull/2) (ветка `feature/lab4-sdd-adr`)

---

## О сквозном проекте «Elor C++»

**Elor** — высокопроизводительное настольное приложение для ОС Windows 11, которое в фоновом режиме перехватывает аудиопоток собеседника во время онлайн-созвонов (Zoom, Microsoft Teams, Google Meet, Discord, Яндекс Телемост) через **Windows WASAPI Loopback / Process Loopback**, выполняет локальную детекцию речевой активности (**Silero VAD** на ONNX Runtime CPU), переводит речь в реальном времени (`p50 ≤ 700 мс`) и выводит субтитры в маскируемом оверлее **DWM** (`WDA_EXCLUDEFROMCAPTURE`, инвариант **Never-Erase**, сквозной клик **Click-Through**, компактный режим **Mini-HUD** и автоэкспорт стенограммы диалога в Markdown/TXT).

### Сводка итерационного планирования (ЛР № 4)
- **Разработанный план P0:** 11 функций (`F01–F11`, приоритеты `10–50`), оценка `47` чел.-дн. Middle (`15 040 BYN`) — превышение дедлайна 8 недель на 7 дней.
- **Раунд 1 (План P1):** 5 технических оптимизаций без урезания скоупа (`-7` дн.) → **`40` чел.-дн. (`12 800 BYN`)**, график на **4 двухнедельные итерации** (8 недель, вехи `M1–M4`).
- **Раунд 2 (План P2):** добавление требования **CHG-002** (двусторонний перевод `RU ↔ EN` + экспорт стенограммы, `+7` дн.) с сохранением дедлайна 8 недель за счёт привлечения со 2-й итерации **Junior C++ разработчика** (`12` дн. × `160 BYN`) → **итоговый бюджет `14 720 BYN`**, срок строго **8 недель (4 итерации)**.

---

## Структура веток репозитория

| Ветка | Назначение |
|---|---|
| `main` | Актуальная основная ветка с влитыми спецификациями ЛР № 3 (`SRS`) и ЛР № 4 (`SDD`, `ADR`, `ROADMAP`, `NEGOTIATIONS`) |
| `feature/lab3-srs` | Разработка и рецензирование спецификации требований SRS (см. [PR #1](https://github.com/vodopad-ik/SDLC/pull/1)) |
| `feature/lab4-sdd-adr` | Разработка SDD, ADR 0001–0006, дорожной карты и 2 раунда переговоров (см. [PR #2](https://github.com/vodopad-ik/SDLC/pull/2)) |
| `ProjectTemplate` | Базовый шаблон структуры каталогов (ЛР № 2) |
| `lab1` | Исходный проект ЛР № 1 («Калькулятор суточной нормы протеина», C++ / Qt Widgets / MVC) |
