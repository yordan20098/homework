#include<stdio.h>

int main()
{
    int a = 18, b = 12;
    for(int i=2;i>0;i++)
    {
        if(i%a == 0 && i%b == 0)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
