#include "mystrings.h"
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]) 
{
    if (argc!=2) 
    {
        return 1;
    }

    if (strlen(argv[1])>50||strlen(argv[2])>50) 
    {
        printf("Error: Maximum length of strings should not exceed 50 characters.\n");
        return 1;
    }

char result[100];
strconcat(result,argv[1],argv[2]);
printf("%s\n",result);
return 0;
}
