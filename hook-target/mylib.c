#include <stdio.h>
#include "mylib.h"

int foo_int(int bar) {
    int barbar;
    printf("libmylib.so, int foo_int(int), bar=%d\n", bar);
    barbar = bar + 1;
    return barbar;
}

void foo_struct(struct demo_struct s) {
    printf("libmylib.so, void foo_struct(struct demo_struct), demo_struct::ca=0x%x\n", s.ca);
    printf("libmylib.so, void foo_struct(struct demo_struct), demo_struct::cb=0x%x\n", s.cb);
    printf("libmylib.so, void foo_struct(struct demo_struct), demo_struct::cc=0x%x\n", s.cc);
    printf("libmylib.so, void foo_struct(struct demo_struct), demo_struct::u32_a=0x%x\n", s.u32_a);
    printf("libmylib.so, void foo_struct(struct demo_struct), demo_struct::u32_b=0x%x\n", s.u32_b);
    printf("libmylib.so, void foo_struct(struct demo_struct), demo_struct::b=0x%lx\n", s.b);
    return;
}

