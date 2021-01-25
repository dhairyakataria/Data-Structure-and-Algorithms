
#include <stdio.h>

int min_count( int Coins[], int n, int money)
{
    int arr[money+1], i, j, var;
    for( i=1; i<money+1; i++)
        arr[i] = 1000;
    arr[0] = 0;
    
    for( i=1; i<=money; i++)
    {
        for( j=0; j<n; j++)
        {
            if( i>=Coins[j] )
            {
                var = arr[i-Coins[j]];
                if(var!=1000 && var+1<arr[i])
                {
                    arr[i] = var+1;
                }
            }
        }
    }
    return arr[money];
}

int main()
{
    int n, count;
    int Coins[3] = { 1,3,4 };
    scanf("%d", &n);

    count = min_count(Coins, 3, n);
    
    printf("%d", count);
    return 0;
}
