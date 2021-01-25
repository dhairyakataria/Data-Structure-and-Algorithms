
#include <stdio.h>

int main()
{
    int d, m, n, i, count=0, last_refilled=0, current_reffil=0;
    scanf("%d", &d);
    scanf("%d", &m);
    scanf("%d", &n);

    int ar[n+1];
    for( i=0; i<n; i++)
    {
        scanf("%d", &ar[i]);
    }
    ar[n]=d;
    
    while(current_reffil<n)
    {
        last_refilled=current_reffil;
        while(ar[current_reffil+1]-ar[last_refilled] < m)
        {
            current_reffil++;
            if(current_reffil==n)
                break;
        }
        
        if(current_reffil==last_refilled)
        {
            count=-1;
            break;
        }
        if(current_reffil<n)
            count++;
    }
    printf("%d\n", count);
    
        
    return 0;
}
