#include "dynstr.h"
#include <stdlib.h>
#include <string.h>

void ensure_capacity(String *string, size_t plus_chars) {
    size_t desired_capacity = string->length + plus_chars;

    if (string->capacity < desired_capacity) {
        string->capacity *= 2;
        while (string->capacity < desired_capacity) {
            string->capacity *= 2;
        }

        string->buf = realloc(string->buf, sizeof(char) * string->capacity);
    }
}

String string_new(str const init) {
    size_t len = strlen(init);
    size_t capacity = len + 1;

    str ptr = malloc(sizeof(char) * capacity);
    memcpy(ptr, init, capacity);

    return (String){.capacity = capacity, .length = len, .buf = ptr};
}

inline void string_drop(String *str) {
    str->capacity = 0;
    str->length = 0;

    free(str->buf);
}
