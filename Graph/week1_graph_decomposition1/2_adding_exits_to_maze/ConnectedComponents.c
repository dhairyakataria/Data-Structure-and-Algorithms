#include <stdio.h>
int fun(int n, int arr[n][n], int x, int m)
{
    int i, count=0, zero=0;
    
    for( i=1; i<n; i++)
	{
	    if(arr[x][i]==-1)
	    {
	            arr[x][i] = m;
	            arr[i][x] = m;
	            count = fun(n, arr, i, m);
	            count ++;
	    }
	    if(arr[x][i]!=0)
	        zero = 1;
	    
	}
	if(zero == 0)
	    return 1;
	else if(count == 0)
	    return 0;
	else
	    return count;
}

int main(void) 
{
	int n, edges, i, var1, var2, x, total=0, j, ans, count=0;
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
	    
	    arr[var1][var2] = -1;
	    arr[var2][var1] = -1; 
	}   
	
	/*for( i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }*/
    for( i=1; i<n; i++)
    {
        ans = fun(n, arr, i, i);
        if(ans>0)
            count++;
    }
    printf("%d\n", count);
	return 0;
}

