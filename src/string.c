/*
 * Copyright (C) 2024 Jesús "YisusGaming" Blanco
 *
 * string.c : Dynamic string.
 */

#include "dynstr.h"
#include <stdlib.h>
#include <string.h>

void ensure_capacity(String *string, size_t plus_chars)
{
    if (string->capacity == 0) {
        string->capacity = 1;
    }

    size_t desired_capacity = string->length + plus_chars;

    if (string->capacity < desired_capacity) {
        string->capacity *= 2;
        while (string->capacity < desired_capacity) {
            string->capacity *= 2;
        }

        string->buf = realloc(string->buf, sizeof(char) * string->capacity);
    }
}

String string_new(str const init)
{
    size_t len = strlen(init);
    size_t capacity = len + 1;

    str ptr = malloc(sizeof(char) * capacity);
    memcpy(ptr, init, capacity);

    return (String){ .capacity = capacity, .length = len, .buf = ptr };
}

void string_pushc(String *string, char c)
{
    ensure_capacity(string, 2);

    string->buf[string->length] = c; // push
    string->length++;

    string->buf[string->length] = '\0';
}

void string_pushstr(String *string, str const s)
{
    ensure_capacity(string, strlen(s) + 1);

    strcat_s(string->buf, string->capacity, s);
}

char string_pop(String *string)
{
    string->length--;
    char c = string->buf[string->length];

    string->buf[string->length] = '\0';

    return c;
}

inline void string_drop(String *string)
{
    string->capacity = 0;
    string->length = 0;

    free(string->buf);
}
