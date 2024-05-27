#include <stdio.h>

int foo(int bar) {
    int barbar;
    printf("Hello from the dynamic library, bar: %d\n", bar);
    barbar = bar + 1;
    return barbar;
}

