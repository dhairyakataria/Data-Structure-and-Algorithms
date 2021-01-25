
#include <stdio.h>

int main()
{
    int s, p, i, count=0;
    scanf("%d %d", &s, &p);
    int a[s], b[s], pp[p];
    for( i=0; i<s; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    for( i=0; i<p; i++)
    {
        scanf("%d", &pp[i]);
    }
    
    
    for(int j=0; j<p; j++)
    {
        count=0;
        for( i=0; i<s; i++)
        {
            if(a[i]<=pp[j] && pp[j]<=b[i])
            {
                count++;
            }
        }
        printf("%d ", count);
    }

    return 0;
}
