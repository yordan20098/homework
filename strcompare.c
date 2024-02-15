#include "mystrings.h"
#include <stdio.h>

int main(int argc,char *argv[]) 
{
    if (argc!=2) 
    {
        return 1;
    }

int result=strcompare(argv[1],argv[2]);
printf("%d\n",result);
return 0;
}
