/*
 * Copyright (C) 2024 Jesús "YisusGaming" Blanco
 * Released under the MIT License.
 *
 * See LICENSE for details.
 *
 * types.h : Type definitions for your code.
 */

#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float  f32;
typedef double f64;

typedef size_t usize;

typedef char const *str;
typedef char       *ncstr;

#define null 0
#define nullptr ((void *)0)
#define fnptr(fn, ...) (*fn)(__VA_ARGS__)

#endif // ! TYPES_H
