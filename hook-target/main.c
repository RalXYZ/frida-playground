#include <stdlib.h>
#include <unistd.h>
#include "mylib.h"

int main() {
    while (1) {
        foo(1);
	    sleep(1);
    }
    return 0;
}
