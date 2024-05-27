#ifndef MYLIB_H
#define MYLIB_H

#include <stdint.h>

struct demo_struct {
    uint32_t u32_a;
    uint32_t u32_b;
    uint64_t u64_a;
};

int foo_int(int);
void foo_struct(struct demo_struct);
void foo_struct_ptr(struct demo_struct*);

#endif // MYLIB_H
