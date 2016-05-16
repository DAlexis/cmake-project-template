# CMake project template

This is my C++ project template using `cmake` build system. It reflect typical directories structure 
and assumed that project consists of
- Static or dynamic libraries
- Executables
- Unit tests made with `gtest`

It contains some useful scripts:
- `build.sh` builds project in directory named `build`. It simply run `cmake` than `make`.
  Build type may be set by giving `debug`/`release` parameter to script. Debug is default/
- `generate-eclipse-project.sh` generates project for Eclipse by cmake file in directory `eclipse-workspace`/
  This project may be imported to eclipse. Sources will not be copied and build files will not be mixed with it

This project template supports `add_subdirectory(...)` semantics. This means this project may be used
as a subproject of any other project based on this template without collisions

One-command build scripts and eclipse project generation scripts are provided.

