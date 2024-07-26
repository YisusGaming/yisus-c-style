/*
 * Copyright (C) 2024 Jesús "YisusGaming" Blanco
 * Released under the MIT License.
 *
 * See LICENSE for details.
 *
 * dynstr.h : Dynamic string.
 */

#ifndef YISUS_STRING_H
#define YISUS_STRING_H

#include "types.h"

/// Dynamic String implementation.
typedef struct
{
    usize capacity;
    usize length;
    str   buf;
} String;

#define cstr(string) string.buf

#define string_null()                                                          \
    (String)                                                                   \
    {                                                                          \
        .capacity = 0, .length = 0, .buf = nullptr                             \
    }

/// Creates a new String from `init`.
/// This will allocate a new buffer with enough capacity for `init`, and then
/// it'll `memcpy` all the characters from `init` to this buffer.
String string_new(str const init);

/// Pushes a character at the end of the String.
void string_pushc(String *string, char c);
/// Pushes a C string at the end of the String.
void string_pushstr(String *string, str const s);
/// Pops a character from the end of the String and returns it.
char string_pop(String *string);

/// Frees the buffer of this String and sets it to `null` and 0.
void string_drop(String *string);

#endif //! YISUS_STRING_H
