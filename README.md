# GraphingCALC

A C++ graphing calculator with an SFML-based GUI. Type any math expression using `x` as the variable and the app plots it in real time. Supports panning, zooming, Cartesian/Polar switching, and a history of the last five equations.

## Features

- Evaluates arbitrary expressions: `sin`, `cos`, `tan`, `ln`, `+`, `-`, `*`, `/`, `^`
- Real-time 2D plotting on a 1400×800 canvas
- Pan (arrow keys), zoom in/out (`O`/`P`), and reset (`,`)
- Toggle between Cartesian and Polar coordinate systems
- Sidebar showing live mouse position and last key pressed
- History of the 5 most recently entered equations, clickable as preset buttons

## Prerequisites

- **CMake 3.5+**
- **C++17** compiler (GCC or MSVC)
- Internet access at configure time — SFML 2.6.x and GoogleTest are fetched automatically via CMake FetchContent

## Build

```bash
cmake -S . -B build
cmake --build build
```

Binaries are placed in `build/bin/`.

## Run

Run the executable from the **project root** so that the `fonts/` directory and `includes/read.txt` are found at their expected relative paths:

```bash
./build/bin/main
```

## Controls

| Input | Action |
|---|---|
| Type in textbox, press `Tab` | Submit expression and plot it |
| `Enter` | Focus the equation textbox |
| Arrow keys | Pan the graph |
| `O` | Zoom in |
| `P` | Zoom out |
| `,` | Reset view |
| **Polar** button | Toggle Cartesian / Polar mode |
| **Reset** button | Reset the graph |
| Click eq1–eq5 buttons | Load a previously entered equation |
| `Escape` | Quit |

## Supported Syntax

```
sin(x) + cos(x)
x^2 - 3*x + 2
ln(x)
tan(x) / x
```

Use `x` (or `X`) as the variable. Standard operator precedence and parentheses are supported.

## Running Tests

```bash
cmake --build build
./build/bin/basic_test
./build/bin/testB
```

## Project Structure

```
.
├── main.cpp                        # Entry point
├── CMakeLists.txt
├── fonts/                          # TTF fonts loaded at runtime
├── includes/
│   ├── constants.h                 # Screen/panel dimensions
│   ├── animate/                    # Main game loop, event handling, UI wiring
│   ├── system/                     # Manages animated objects
│   ├── graph/                      # Graph rendering
│   ├── graph_info/                 # Graph configuration struct
│   ├── plot/                       # Equation evaluation across x domain
│   ├── tokenizer/                  # String → token list
│   ├── shunting_yard/              # Infix → postfix (RPN) conversion
│   ├── rpn/                        # RPN evaluator
│   ├── cord_translator/            # Cartesian ↔ Polar conversion
│   ├── sidebar/                    # Sidebar UI component
│   ├── SMFL_BS/                    # SFML Button and Textbox widgets
│   ├── token/                      # Token types (Integer, Operator, Function, Parens)
│   ├── queue/, stack/, vector/     # Custom data structure implementations
│   └── read.txt                    # Persisted equation history (5 slots)
└── _tests/
    └── _test_files/                # GoogleTest suites
```
