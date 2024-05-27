#include <stdlib.h>
#include <unistd.h>
#include "mylib.h"

int main() {
    struct demo_struct* sp = malloc(sizeof(struct demo_struct));
    sp->u32_a = 0xce;
    sp->u32_b = 0xbb;
    sp->u64_a = 0xbc;
    
    while (1) {
        foo_int(1);
	    sleep(1);

        foo_struct((struct demo_struct){.u32_a = 0x2e, .u32_b = 0xcc, .u64_a = 0x3edc});
        sleep(1);

        foo_struct_ptr(sp);
        sleep(1);
    }
    return 0;
}
