# Arena-Simulation

This is an arena simulation where AI bots,
created using a genetic algorithm, will fight, learn, and evolve to win.

The project is built with **C++20** and **SFML 3**.

The simulation is built entirely from scratch. I am developing this project out of personal interest
and a desire to practice C++ while gaining hands-on knowledge of how genetic algorithms,
game engines, build systems, and low-level C++ development work.

## Current status

The project is currently being migrated from **SFML 2 to SFML 3.1**.

The build system has also been reworked to use a CMake superbuild:
- SFML is downloaded and built separately from the application;
- the application uses the installed SFML package through `find_package`;
- CMake Presets provide a common build interface;
- Ninja is used as the build system.

The SFML 3 API migration is still in progress.

## Building

### Prerequisites

* **CMake 3.28+**
* **Ninja**
* **Git**
* A compiler with **C++20** support

SFML itself does not need to be installed manually.
The superbuild downloads and builds **SFML 3.1.0** automatically.

### Linux

On Ubuntu/Debian, install the required tools and system libraries:

```bash
sudo apt update

sudo apt install \
    build-essential \
    cmake \
    ninja-build \
    git \
    libxrandr-dev \
    libxcursor-dev \
    libxi-dev \
    libudev-dev \
    libfreetype-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    libharfbuzz-dev