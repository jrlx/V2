[![OpenSSF Scorecard](https://api.scorecard.dev/projects/github.com/jrlx/V2/badge)](https://scorecard.dev/viewer/?uri=github.com/jrlx/V2)
[![OpenSSF Best Practices](https://www.bestpractices.dev/projects/PROJECT_ID/badge)](https://www.bestpractices.dev/projects/PROJECT_ID)

# Visualizer

Visualizer is a real-time audio waveform visualizer written in C++17 using SFML and Dear ImGui. It loads an audio file, plays it back, and draws a live waveform of the audio at the current playback position.

## Features

- Load, play, pause and stop audio files
- Real-time waveform display that follows playback
- Native file dialog for choosing audio files
- Playback progress bar
- High-DPI scaling on Windows

Supported formats are WAV, OGG, FLAC and MP3.

## Dependencies

The following libraries are downloaded automatically by CMake:

- SFML 2.6
- Dear ImGui 1.89.9
- ImGui-SFML 2.6
- nativefiledialog-extended 1.2.1

You need a C++17 compiler, CMake 3.29 or newer, and Git. On Linux you also need the development packages for X11, OpenAL, FLAC, Vorbis, OpenGL, FreeType and GTK 3.

## Building

    git clone https://github.com/jrlx/V2.git
    cd V2
    cmake -B build
    cmake --build build

## Running

    ./build/main

On Windows the executable is in build\Debug or build\Release.

## Testing

Automated tests are built with the project and run with CTest:

    ctest --test-dir build --output-on-failure

Every push and pull request is built and tested by GitHub Actions, and the code is scanned with CodeQL.

## Usage

1. Choose File > Open, or type the path to an audio file in the Audio File box.
2. Click Load.
3. Use Play, Pause and Stop to control playback.

## Project Structure

- main.cpp: application window and main loop
- AudioPlayer: loads and plays audio
- UIManager: menu bar and audio control panel
- FileDialog: native open-file dialog
- Visualizer: base class for visualizations
- WaveformVisualizer: draws the waveform
- HighDpi.h: DPI scaling on Windows
- tests: automated tests
- projectFiles: project report and presentation

## Contributing

Report bugs or suggest features by opening an issue at https://github.com/jrlx/V2/issues. Pull requests are welcome. See CONTRIBUTING.md for requirements and the testing policy.

## Security

To report a vulnerability, see SECURITY.md.

## Releases

Changes in each release are listed in CHANGELOG.md.

## License

This project is licensed under the MIT License. See the LICENSE file.
