#include <stdio.h>
#include<time.h> 
#include <stdlib.h> 


long int product_fast(int ar[], int n)
{
    int i, index=-1;
    int largest1=-1, largest2=-1;
    
    for(i=0; i<n; i++)
    {
        if(ar[i]> largest1)
        {
            largest1 = ar[i];
            index = i;
        }
    }
    
    for( i=0; i<n; i++)
    {
        if(ar[i]>largest2 && i!=index)
        {
            largest2 = ar[i];
        }
    }
    
    return (long int)largest1*largest2;
}

int main()
{
        int n, i;
        long int result2=0;
        scanf("%d",&n);
        int ar[n];
        
        for( i=0; i<n; i++)
            scanf("%d",&ar[i]);
            
        result2 = product_fast(ar, n);
        
        printf("%ld\n",result2);
    
    
    return 0;
}
