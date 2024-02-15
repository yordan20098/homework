#include <stdio.h>
#include <limits.h>

#define PRINT_TYPE_INFO(type) \
    printf("%-15s%-10lu%-20ld%-20ld%-20ld%-20ld%-15lu\n", \
           #type, sizeof(type), (long)INT_MIN, (long)INT_MAX, (long)UINT_MAX, 0L, (unsigned long)ULONG_MAX)

int main() {
    printf("%-15s%-10s%-20s%-20s%-20s%-20s%-15s\n", "Type", "Size", "Min (signed)", "Max (signed)", "Max (unsigned)", "Min (unsigned)", "Max (unsigned)");

    PRINT_TYPE_INFO(char);
    PRINT_TYPE_INFO(short);
    PRINT_TYPE_INFO(int);
    PRINT_TYPE_INFO(long);

    return 0;
}
