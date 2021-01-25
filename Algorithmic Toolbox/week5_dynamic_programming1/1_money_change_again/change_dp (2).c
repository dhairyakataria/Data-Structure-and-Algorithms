
#include <stdio.h>

int main()
{
    int n, count;
    scanf("%d", &n);

        if(n>=4)
        {
            count = n/4;
            n=n%4;
        }
        if(n==3)
        {
            count++;
            n = 0;
        }
        if(n==2)
        {
            if(count>0)
            {
                count++;
                n=0;
            }
            else
            {
                count=2;
            }
        }
        if(n==1)
        {
            count++;
            n=0;
        }
        
    printf("%d", count);
    return 0;
}
