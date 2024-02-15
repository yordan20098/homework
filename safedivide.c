#include <stdio.h>
#include <stdlib.h>
#include "safeint.h"
#include "util.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
       return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    struct SafeResult result = safedivide(a, b);

    if (result.errorflag) {
        printError("Division by zero or overflow occurred.");
        return 1;
    }

    printf("Quotient: %d\n", result.value);

    return 1;
}
