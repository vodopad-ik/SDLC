# ADR 0003 — Стек: C++23 + Qt 6.8 LTS, CMake + vcpkg

- **Статус**: принято (2026-10-18)

## Решение
- Язык: C++23 (MSVC v143 из VS 2022 Build Tools), `std::expected` для ошибок.
- UI: Qt 6.8 LTS, Qt Quick/QML (GPU-рендеринг, прозрачность, окна без рамки). Win32-флаги окна — через `HWND` из `QWindow::winId()`.
- Сеть в engine: Qt Network (HTTP/2, TLS через Schannel — без OpenSSL) и Qt WebSockets.
- Аудио: чистый WASAPI + WIL. Чистые доменные модули — только стандартная библиотека.
- Сборка: CMake ≥ 3.28, Ninja, CMakePresets; зависимости — vcpkg manifest; Qt — prebuilt через aqtinstall
  (сборка Qt из vcpkg занимает часы).
- Тесты: GoogleTest + CTest. Формат/статанализ: clang-format, clang-tidy (LLVM).

## Альтернативы
- Tauri 2 + React: красивее и быстрее верстать, но три языка (C++/Rust/TS), три системы сборки и Chromium в памяти.
- Rust целиком: отказ от C++-стека, который является учебной целью и даёт прямой доступ к WinAPI/whisper.cpp/OpenVINO.
- Dear ImGui: максимально легко, но выглядит как отладочный инструмент.

## Последствия
- Qt под LGPL — только динамическая линковка (стандартная поставка `windeployqt`).
- Один язык и одна система сборки на весь проект.
