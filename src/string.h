#ifndef YISUS_STRING_H
#define YISUS_STRING_H

#include "types.h"

typedef struct {
    size_t capacity;
    size_t length;
    str buf;
} string;

#define string_null()                                                       \
    (string) { .capacity = 0, .length = 0, .buf = null }

string string_new(str const init);
void string_drop(string *str);

#endif //! YISUS_STRING_H
