
#include <stdio.h>

int main()
{
    int n, total_coins=0;
    scanf("%d", &n);
    if(n>=10)
    {
        total_coins += n/10;
        n = n%10;
    }
    if(n>=5)
    {
        total_coins += n/5;
        n = n%5;
    }
    total_coins += n;
    
    printf("%d\n", total_coins);
    return 0;
}
