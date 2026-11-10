# ADR 0004 — Облачный ИИ, Gemini первым провайдером

- **Статус**: принято (2026-10-18)

## Контекст
Без дискретной GPU локальные модели на Core Ultra 5 125H дают ответ за 2–5 с — не укладывается в N1 (≤ 1 с).
У пользователя есть бесплатный ключ Gemini API.

## Решение
- Только облако в MVP. Провайдеры за интерфейсами `ISttProvider` и `ILlmProvider`.
- STT: Gemini Live API (WebSocket `BidiGenerateContent`), транскрипционная модель
  (на 2026-10: `gemini-3.5-transcribe-live`, поля `interimInputTranscription` / `inputTranscription`,
  PCM 16 kHz mono s16, чанки ~100 мс).
- LLM: `streamGenerateContent?alt=sse`; перевод — Flash-Lite (на 2026-10: `gemini-3.5-flash-lite`),
  ассистент — Flash (на 2026-10: `gemini-3.8-flash`) с минимальным уровнем «мышления».
- ID моделей — только в конфиге; перед реализацией сверять с https://ai.google.dev/gemini-api/docs/models.

## Риски
- Лимиты бесплатного тарифа (RPM/RPD, параллельные Live-сессии) → обработка 429, деградация на Flash-Lite, индикатор квоты.
- На бесплатном тарифе Google может использовать данные для улучшения продуктов → предупреждение в настройках.
- Изменения API/моделей → контрактные тесты на записанных ответах + live smoke-тест по флагу.

## Последствия
- Добавление Deepgram/Groq/OpenAI/Claude или локальных моделей не меняет ядро.
