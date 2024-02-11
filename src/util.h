/*
 * Copyright (C) 2024 Jesús "YisusGaming" Blanco
 *
 * util.h : Useful utilities.
 */

#ifndef YISUS_UTIL_H
#define YISUS_UTIL_H

#include "types.h"
#include <stdio.h>

#define eprintf(f, ...) fprintf(stderr, f, __VA_ARGS__)
#define failifnull(with, check, msg, ...)                                      \
    if (check == null) {                                                       \
        eprintf(msg, __VA_ARGS__);                                             \
        return with;                                                           \
    }
#define abortifnull(code, check, msg, ...)                                     \
    if (check == null) {                                                       \
        eprintf(msg, __VA_ARGS__);                                             \
        exit(code);                                                            \
    }
#define retifnull(check, msg, ...)                                             \
    if (check == null) {                                                       \
        eprintf(msg, __VA_ARGS__);                                             \
        return;                                                                \
    }
#define errifnull(check, msg, ...)                                             \
    if (check == null) {                                                       \
        eprintf(msg, __VA_ARGS__);                                             \
    }

#endif //! YISUS_UTIL_H
