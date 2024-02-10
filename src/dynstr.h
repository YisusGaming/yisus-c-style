/*
 * Copyright (C) 2024 Jesús "YisusGaming" Blanco
 *
 * dynstr.h : Dynamic string.
 */

#ifndef YISUS_STRING_H
#define YISUS_STRING_H

#include "types.h"

typedef struct
{
    size_t capacity;
    size_t length;
    str buf;
} String;

#define cstr(string) string.buf

#define string_null()                                                          \
    (String)                                                                   \
    {                                                                          \
        .capacity = 0, .length = 0, .buf = null                                \
    }

String string_new(str const init);

void string_pushc(String *string, char c);
void string_pushstr(String *string, str const s);
char string_pop(String *string);

void string_drop(String *string);

#endif //! YISUS_STRING_H
