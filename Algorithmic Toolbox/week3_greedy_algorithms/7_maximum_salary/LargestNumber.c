#include<stdio.h>

int greater_number(int x, int y)
{
    
    int a=x, b=y, mul_a=1, mul_b=1, n=4;
    while(n>0)
    {
        mul_a=1;
        mul_b=1;
        while(a>=10)
        {
            a = a/10;
            mul_a *= 10;
        }   
        //printf("a=%d\t", a);
        while(b>=10)
        {
            b = b/10;
            mul_b *= 10;
        }
        //printf("b=%d\n", b);
        if(b>a)
            return 1;
        else if(a>b)
        {
            return 0;
        }
        else
        {
            if(mul_a==1)
                mul_a=10;
            if(mul_b==1)
                mul_b=10;
            a = x%mul_a;
            b = y%mul_b;
        }
        n--;
    }
    return 1;
}



int main()
{
    int n, i, var, j;
    scanf("%d", &n);
    int arr[n];
    for( i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for( i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            //printf("%d\t%d\n", arr[i], arr[j]);
            if(greater_number(arr[i], arr[j]) == 1)
            {
              //  printf("in if %d\t%d\n", arr[i], arr[j]);
                var = arr[i];
                arr[i] = arr[j];
                arr[j] = var;
            }
        }
    }
    for( i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
}