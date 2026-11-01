# Changelog

All notable changes to this project are documented in this file. This project uses semantic versioning.

## [1.0.0] - 2026-11-01

### Added
- Real-time waveform visualizer with audio playback (load, play, pause, stop)
- Native file dialog and playback progress bar
- Automated tests for AudioPlayer, run with CTest
- Continuous integration build and test workflow
- CodeQL static analysis and OpenSSF Scorecard workflows
- LICENSE (MIT), SECURITY.md, CONTRIBUTING.md

### Fixed
- Native file dialog library was shut down immediately after being initialized
- Progress bar divided by zero before a file was loaded
- Compiler warnings in main.cpp and HighDpi.h

### Security
- No known vulnerabilities fixed in this release.
