#include<stdio.h>

int main()
{
    long int n, k, l, count=0;
    scanf("%ld", &n);
    int arr[n];
    for(k=n, l=1; k>0; l++)
    {
        if(k<=2*l)
        {
            arr[count]=k;
            k-=k;
            count++;
            break;
        }
        else
        {
            arr[count]=l;
            k-=l;
            count++;
        }
    }
    
    printf("%ld\n", count);
    for(int i=0; i<count; i++)
        printf("%d ", arr[i]);
    
}