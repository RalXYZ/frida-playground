#include <stdio.h>
#include "mylib.h"

int foo_int(int bar) {
    int barbar;
    printf("libmylib.so, int foo_int(int), bar=%d\n", bar);
    barbar = bar + 1;
    return barbar;
}

void foo_struct(struct demo_struct s) {
    printf("libmylib.so, void foo_struct(struct demo_struct), demo_struct::u32_a=0x%x\n", s.u32_a);
    printf("libmylib.so, void foo_struct(struct demo_struct), demo_struct::u32_b=0x%x\n", s.u32_b);
    printf("libmylib.so, void foo_struct(struct demo_struct), demo_struct::u64_a=0x%lx\n", s.u64_a);
    return;
}

void foo_struct_ptr(struct demo_struct* sp) {
    printf("libmylib.so, void foo_struct_ptr(struct demo_struct*), demo_struct->u32_a=0x%x\n", sp->u32_a);
    printf("libmylib.so, void foo_struct_ptr(struct demo_struct*), demo_struct->u32_b=0x%x\n", sp->u32_b);
    printf("libmylib.so, void foo_struct_ptr(struct demo_struct*), demo_struct->u64_a=0x%lx\n", sp->u64_a);
    return;
}

