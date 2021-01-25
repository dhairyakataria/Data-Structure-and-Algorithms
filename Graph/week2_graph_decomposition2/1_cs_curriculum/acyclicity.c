#include <stdio.h>
int top;

void push(int n, int *stack)
{
    top++;
    stack[top] = n;
}


void pop(int *stack)
{
    top--;
}


int explore(int x, int n, int arr[n][n], int *v_to_go, int *stack, int *visited)
{
    int i, j, ans=-1;
    for( i=1; i<n; i++)
    {
        if(arr[x][i]==1)
        {
            for( j=0; j<=top; j++)
            {
                if(stack[j]==i)
                {
                    return 0;
                }
            }
            push(i, stack);
            ans = explore(i, n, arr, v_to_go, stack, visited);
            if( ans == 0)
                return 0;
        }
    }
    pop(stack);
    v_to_go[x]=0;
    visited[x]=1;
    return 1;
}

int fun( int n, int arr[n][n], int *v_to_go, int *stack, int *visited)
{
    int i, ans=-1;
    for( i=1; i<n; i++)
    {
        top=-1;
        if(v_to_go[i]==1)
        {
            push(i, stack);
            ans = explore(i, n, arr, v_to_go, stack, visited);
            if( ans==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) 
{
    int n, edge, i, j, var1, var2, ans;
    scanf("%d %d", &n, &edge);
    n = n+1;
    int arr[n][n], v_to_go[n], stack[n], visited[n];
    
    for( i=0; i<n; i++)
        v_to_go[i] = 1;
        
    for( i=0; i<n; i++)
        visited[i] = 0;

    for( i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
            arr[i][j] = 0;
    }
    
    for(i=0; i<edge; i++)
    {
        scanf("%d %d", &var1, &var2);
        arr[var1][var2] = 1;
    }
    
    ans = fun( n, arr, v_to_go, stack, visited);
    if(ans == 0)
        printf("1\n");
    else
        printf("0\n");
	return 0;
}

