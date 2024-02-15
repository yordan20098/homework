#include "transformation.h"
#include <string.h>
struct transformation transform_string(char*input)
{
    int ok=1;
    struct transformation a;
    a.result=0;
    for(int i=0;i<strlen(input);i++)
    {
          if(input[i]<'0' || input[i]>'9')
        {
            ok=0;break;
        }
    }
    if(ok)
    {
        strcpy(a.error," ");
        for(int i=0;i<strlen(input);i++)
        {
            a.result=a.result*10+(input[i]-'0');
        }
    }
    else{
        a.result=0;
        strcpy(a.error,"Invalid input");
    }
    return a;
}
