#include "dynstr.h"
#include "types.h"
#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

static void signal_handler(i32 sig)
{
    if (sig == SIGABRT) {
        printf("\x1B[1;33mtest \x1B[1;39mt_string\x1B[1;33m... "
               "\x1B[1;31mfailed\x1B[0m\n");
    }
}

i32 main(void)
{
    signal(SIGABRT, signal_handler);
    String str = string_null();

    string_pushc(&str, 'a');
    assert(str.capacity == 2);
    assert(str.length == 1);
    assert(strcmp(cstr(str), "a") == 0);

    string_pushstr(&str, "aaa");
    assert(str.capacity == 8);
    assert(str.length == 4);
    assert(strcmp(cstr(str), "aaaa") == 0);

    string_drop(&str);
    assert(str.buf == nullptr);
    assert(str.capacity == 0);
    assert(str.length == 0);
    
    printf(
        "\x1B[1;33mtest \x1B[1;39mt_string\x1B[1;33m... \x1B[1;32mok\x1B[0m\n");
    return 0;
}
