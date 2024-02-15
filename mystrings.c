#include "mystrings.h"
#include <string.h>

int strlength(const char *str) 
{
    return strlen(str);
}

void strconcat(char *result, const char *str1, const char *str2) 
{
    strcpy(result,str1);
    strcat(result,str2);
}

int strcompare(const char *str1, const char *str2) 
{
    return strcmp(str1,str2);
}
