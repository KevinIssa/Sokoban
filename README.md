# Sokoban

Project developed as part of the **Programming Languages II** course at the **Université Libre de Bruxelles (ULB)**.

## Description

This project is a **C++** implementation of the classic **Sokoban** puzzle game, featuring a graphical user interface built with **FLTK (Fast Light Toolkit)**.

The objective of the game is to push all the crates onto the designated target tiles while avoiding situations where a crate becomes permanently stuck.

## Features

- Graphical user interface built with FLTK
- Player movement
- Crate and target management
- Win condition detection
- Level loading
- Object-oriented C++ design

## Prerequisites

Before building the project, make sure you have installed:

- A C++ compiler (GCC, Clang, MSVC, etc.)
- **FLTK (Fast Light Toolkit)**
- **Make**

### Installing FLTK

#### Ubuntu / Debian

```bash
sudo apt install libfltk1.3-dev
```

#### macOS (Homebrew)

```bash
brew install fltk
```

## Build and Run

Compile and launch the game:

```bash
make run
```

Remove generated build files:

```bash
make clean
```

## Authors

- **Kevin Issa**
- **Mickael Kovel**

---

Developed as part of the **Programming Languages II** course at the **Université Libre de Bruxelles (ULB)**.
