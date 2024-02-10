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

#define string_null()                                                          \
    (string)                                                                   \
    {                                                                          \
        .capacity = 0, .length = 0, .buf = null                                \
    }

String string_new(str const init);

void string_pushc(String *str, char c);
char string_pop(String *str);

void string_drop(String *str);

#endif //! YISUS_STRING_H
