#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int foo(int bar) {
    int result = bar + 1;
    return result;
}

int main() {
    while (1) {
        int result = foo(2);
        printf("result = %d\n", result);
        sleep(1);
    }
    return 0;
}


