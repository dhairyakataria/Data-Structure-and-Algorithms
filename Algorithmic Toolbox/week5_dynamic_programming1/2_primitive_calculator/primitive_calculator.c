
#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n+1], temp1, temp2, temp3;
    for( i=0; i<n+1; i++)
    {
        arr[i]=0;
    }
    
    
    for( i=2; i<n+1; i++)
    {
        temp1=100000;
        temp2=100000;
        temp3=100000;
        
        temp1 = arr[i-1] + 1;
        
        if(i%2==0)
        {
            temp2 = (arr[i/2]) + 1;
        }
        
        if(i%3==0)
        {
            temp3 = (arr[i/3]) + 1; 
        }
    
        if(temp1>temp2)
        {
            if(temp2>temp3)
                arr[i] = temp3;
            else
                arr[i] = temp2;
        }
        else
        {
            if(temp1>temp3)
                arr[i] = temp3;
            else
                arr[i] = temp1;
        }
        
    }
    printf("%d\n", arr[n]);
    int result[arr[n]+1], count=0, j=n;
    result[0] = n;
    
    while(n!=1)
    {
        temp1=n;
        temp2=n;
        temp3=n;
        
        temp1 = n - 1;
        if(n%2==0)
            temp2 = n/2;
        if(n%3==0)
            temp3 = n/3;
        
        if(arr[temp1]>arr[temp2])
        {
            if(arr[temp2]>arr[temp3])
                n = n/3;
            else
                n = n/2;
        }
        else
        {
            if(arr[temp1]>arr[temp3])
                n = n/3;
            else
                n = n-1;
        }
        result[++count] = n;
    }
    
    for( i=arr[j]; i>=0; i--)
        printf("%d ", result[i]);
    return 0;
}
