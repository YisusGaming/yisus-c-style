/*
 * Copyright (C) 2024 Jesús "YisusGaming" Blanco
 * Released under the MIT License.
 *
 * See LICENSE for details.
 *
 * types.hpp : Type definitions for your C++ code.
 */

#pragma once

#include <stdint.h>

typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t  int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef float  float32;
typedef double float64;

typedef size_t usize;

typedef char *str;

#define null 0
#define fnptr(fn, ...) (*fn)(__VA_ARGS__)
