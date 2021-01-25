
#include <stdio.h>

int period(long int m)
{
    long int previous = 0, current = 1, i, var;
    for( i=0; i<m*m; i++)
    {
        var = (previous+current)%m;
        previous = current;
        current = var;
        
        
        if (previous == 0 && current == 1)
            break;
    }
    return i+1;
    
}

long int fibonacci( long int n, long int m)
{
    long int x, i, var;
    x = period(m);
    n = n%x;
    
    long int previous = 0, current = 1;
    if(n==0) 
        return 0;
    if(n==1)
        return 1;
    for( i=1; i<n; i++)
    {
        var = (previous+current)%m;
        previous = current;
        current = var;
    }
          
    return (var % m) ;
}

int main()
{
    long int n, m, result;
    
    scanf("%ld %ld", &n, &m);
    result = fibonacci( n, m);
    printf("%ld\n", result);
    return 0;
}
