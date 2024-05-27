#ifndef MYLIB_H
#define MYLIB_H

#include <stdint.h>

struct demo_struct {
    uint8_t ca;
    uint8_t cb;
    uint8_t cc;
    uint32_t u32_a;
    uint32_t u32_b;
    uint64_t b;
};

int foo_int(int);
void foo_struct(struct demo_struct);

#endif // MYLIB_H
