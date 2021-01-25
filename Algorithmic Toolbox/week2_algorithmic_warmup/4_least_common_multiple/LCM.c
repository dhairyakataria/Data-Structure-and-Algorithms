
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


long int LCM(long int a, long int b)  
{  
    return (a*b)/GCD(a, b);  
}  



int main()
{
     long int a, b;
     long int result;
    scanf("%ld %ld", &a, &b);
    result = LCM(a, b);
    printf("%ld\n", result);

    return 0;
}
