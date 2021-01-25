
#include <stdio.h>

int main()
{
    int n1, n2, i, j;
    
    scanf("%d", &n1);
    int arr1[n1];
    for( i=0; i<n1; i++)
        scanf("%d", &arr1[i]);
    
    scanf("%d", &n2);
    int arr2[n2];
    for( j=0; j<n2; j++)
        scanf("%d", &arr2[j]);
        
    int result[n1+1][n2+1];
    for( i=0; i<n1+1; i++)
        result[i][0] = 0;
        
    for( i=0; i<n2+1; i++)
        result[0][i] = 0;
        
    
    for( i=1; i<n1+1; i++)
    {
        for( j=1; j<n2+1; j++)
        {
            //printf("%d %d\n", arr1[i-1], arr2[j-1]);
            if(arr1[i-1]==arr2[j-1])
                result[i][j] = 1 + result[i-1][j-1];
            else
            {
                if(result[i-1][j] > result[i][j-1])
                    result[i][j] = result[i-1][j];
                else
                    result[i][j] = result[i][j-1];
            }
        }
    }
    
    printf("%d", result[n1][n2]);
    return 0;
}
