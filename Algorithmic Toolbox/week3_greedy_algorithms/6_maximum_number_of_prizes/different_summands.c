#include<stdio.h>

int main()
{
    long int n, var=0, sum=0, count=0;
    scanf("%ld", &n);
    int ar[n];
    while(sum<n)
    {
        if((var+1)*2 >= (n-sum) )
        {
            ar[count] = n-sum;
            sum = n;
            count++;
        }
        else
        {
            ar[count] = ++var;
            sum += var;
            count++;
        }
    }
    
    printf("%ld\n", count);
    for(int i=0; i<count; i++)
        printf("%d ", ar[i]);
    
}