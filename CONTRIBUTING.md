# Contributing to Visualizer

Thank you for your interest in contributing.

## Reporting Bugs and Requesting Features

Open an issue at https://github.com/jrlx/V2/issues. For bugs, include your operating system, the audio file format you used, and steps to reproduce the problem.

Security vulnerabilities should be reported privately as described in SECURITY.md.

## Submitting Changes

1. Fork the repository and create a branch from main.
2. Make your changes.
3. Build the project and run the tests (see below).
4. Open a pull request describing what you changed and why.

## Requirements for Contributions

- Code must be C++17 and build with the project's CMake setup.
- Code must compile without warnings. Warnings are enabled by default (-Wall -Wextra -Wpedantic on GCC and Clang, /W4 on MSVC).
- Follow the existing style: four-space indentation, PascalCase for classes, camelCase for functions and variables, one class per header and source file.
- All tests must pass, and the CI and CodeQL checks must pass on the pull request.

## Testing Policy

New functionality must come with automated tests, and bug fixes should include a test that would have caught the bug when practical. Tests live in the tests directory and are registered with CTest in CMakeLists.txt.

Build and run the tests:

    cmake -B build
    cmake --build build
    ctest --test-dir build --output-on-failure

## License

By contributing, you agree that your contributions will be licensed under the MIT License in the LICENSE file.
