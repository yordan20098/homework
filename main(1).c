#include "transformation.h"
#include <stdio.h>

int main()
{
    char input[]="1h23";
    struct transformation result=transform_string(input);
    printf("\n %ld\n%s",result.result,result.error);
  return 0;
}
