/*
 * Copyright (C) 2024 Jesús "YisusGaming" Blanco
 *
 * cproj.c : CLI util that generates C projects.
 */

#include "types.h"
#include <stdio.h>

#define eprintf(format, ...) fprintf(stderr, format, __VA_ARGS__)

// TODO: Define this with CMake.
#ifndef CLANG_FORMAT_SOURCE
#warning No .clang-format source found.
#define CLANG_FORMAT_SOURCE "# Missing source."
#endif

// TODO: Define this with CMake.
#ifndef CMAKELISTS_SOURCE
#warning No CMakeLists.txt source found.
#define CMAKELISTS_SOURCE "# Missing source."
#endif

i32 main(i32 argc, char **argv)
{
    if (argc < 2) {
        eprintf("cproj error: no metadata provided.\n");
        eprintf("\nusage is: cproj.exe <project name> [path]\n");
        return -1;
    }

    /// TODO: Create project.

    return 0;
}
