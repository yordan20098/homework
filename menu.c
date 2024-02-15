#include <stdio.h>
#include <string.h>

int strlength(const char *str) 
{
    return strlen(str);
}

void strconcat(char *result,char *str1,char *str2) 
{
    strcpy(result,str1);
    strcat(result,str2);
}

int strcompare(const char *str1,const char *str2) 
{
    return strcmp(str1,str2);
}

int main() 
{
    printf("1.strlength - Finds the length of a string.\n");
    printf("2.strconcat - Concatenates two strings.\n");
    printf("3.strcompare - Compares two strings.\n");
    return 0;
}
