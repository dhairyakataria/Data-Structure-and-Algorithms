
#include <stdio.h>

int GCD( int a, int b)
{
    int var;
    if(a>b)
    {
        while(b!=0)
        {
            var = a%b;
            a = b;
            b = var;
        }
        return a;
    }
    else
    {
        while(a!=0)
        {
            var = b%a;
            b = a;
            a = var;
        }
        return b;
    }
}



int main()
{
     int a, b, result;
    scanf("%d %d", &a, &b);
    result = GCD(a, b);
    printf("%d\n", result);

    return 0;
}
