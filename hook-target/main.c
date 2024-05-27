#include <stdlib.h>
#include <unistd.h>
#include "mylib.h"

int main() {
    while (1) {
        foo_int(1);
	    sleep(1);

        foo_struct((struct demo_struct){.ca = 0x5b, .cb = 0x7d, .cc = 0xa2, .u32_a = 0x2e, .u32_b = 0xcc, .b = 0x3edc});
        sleep(1);
    }
    return 0;
}
