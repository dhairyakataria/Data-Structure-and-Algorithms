#include <stdio.h>
int fun(int n, int arr[n][n], int x, int y)
{
    int i, count=0;
    
    for( i=1; i<n; i++)
	{
	    if(arr[x][i]==100)
	    {
	        if(i==y)
	            return 1;
	        else
	        {
	            arr[x][i] = 0;
	            arr[i][x] = 0;
	            count = fun(n, arr, i, y);
	        }
	    }
	    if(count == 1)
	        return 1;
	}
	return 0;
}

int main(void) 
{
	int n, edges, i, var1, var2, x, y, j, ans;
	scanf("%d %d", &n, &edges);
	n++;
	int arr[n][n];
	for( i=0; i<n; i++)
	    arr[0][i]=i;
	for( i=0; i<n; i++)
	    arr[i][0]=i;
	       
	for( i=1; i<n; i++)
	{
	    for( j=1; j<n; j++)
	        arr[i][j] = 0;
	}
	
	for( i=0; i<edges; i++)
	{
	    scanf("%d %d", &var1, &var2);
	    
	    arr[var1][var2] = 100;
	    arr[var2][var1] = 100; 
	}
	scanf("%d %d", &x, &y);
	
	/*for( i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }*/

    ans = fun(n, arr, x, y);
    printf("%d\n", ans);
	return 0;
}

