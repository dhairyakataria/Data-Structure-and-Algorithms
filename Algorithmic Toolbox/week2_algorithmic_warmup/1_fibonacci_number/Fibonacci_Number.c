
#include <stdio.h>

int fib(int n)
{
    int a=0, b=1, sum=0;
    if(n>0)
    {
        while(n-->1)
        {
            sum = a+b;
            a=b;
            b=sum;
        }
        return b;
    }
    return a;
}



int main()
{
    int n, result;
    scanf("%d", &n);
    result = fib(n);
    printf("%d\n", result);

    return 0;
}
