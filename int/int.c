#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int foo(int bar) {
    int result = bar + 1;
    return result;
}

int main() {
    printf ("foo() is at %p\n", foo);
    while (1) {
        int result = foo(2);
        printf("result = %d\n", result);
        sleep(1);
    }
    return 0;
}


