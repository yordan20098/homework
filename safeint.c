#include "safeint.h"
#include <limits.h>

struct SafeResult safeadd(int a, int b) {
    struct SafeResult result;

    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        result.value = 0;
        result.errorflag = 1;
    } else {
        result.value = a + b;
        result.errorflag = 0;
    }

    return result;
}

struct SafeResult safesubtract(int a, int b) {
    struct SafeResult result;

    if ((b > 0 && a < INT_MIN + b) || (b < 0 && a > INT_MAX + b)) {
        result.value = 0;
        result.errorflag = 1;
    } else {
        result.value = a - b;
        result.errorflag = 0;
    }

    return result;
}

struct SafeResult safemultiply(int a, int b) {
    struct SafeResult result;

    if (a > 0) {
        if (b > 0 && a > INT_MAX / b) {
            result.value = 0;
            result.errorflag = 1;
        } else if (b < 0 && b < INT_MIN / a) {
            result.value = 0;
            result.errorflag = 1;
        } else {
            result.value = a * b;
            result.errorflag = 0;
        }
    } else if (a < 0) {
        if (b > 0 && a < INT_MIN / b) {
            result.value = 0;
            result.errorflag = 1;
        } else if (b < 0 && a < INT_MAX / b) {
            result.value = 0;
            result.errorflag = 1;
        } else {
            result.value = a * b;
            result.errorflag = 0;
        }
    } else{
        result.value = 0;
        result.errorflag = 0;
    }

    return result;
}

struct SafeResult safedivide(int a, int b) {
    struct SafeResult result;

    if (b == 0) {
        result.value = 0;
        result.errorflag = 1;
    } else if (a == INT_MIN && b == -1) {
        result.value = 0;
        result.errorflag = 1;
    } else {
        result.value = a / b;
        result.errorflag = 0;
    }

    return result;
}

struct SafeResult safestrtoint(const char* str) {
    struct SafeResult result;

    int convertedValue = atoi(str);
    if (convertedValue == 0 && str[0] != '0') {
        result.value = 0;
        result.errorflag = 1;
    } else {
    
        struct SafeResult addResult = safeadd(convertedValue, 0);
        if (addResult.errorflag == 1) {
            result.value = 0;
            result.errorflag = 1;
        } else {
            result.value = convertedValue;
            result.errorflag = 0;
        }
    }

    return result;
}
