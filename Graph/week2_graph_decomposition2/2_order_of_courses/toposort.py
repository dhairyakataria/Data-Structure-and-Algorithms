def dfs(adj, visited, arr, s):
    ls = adj[s]
    for i in ls:
        if(visited[i]==0):
            visited[i] = 1
            dfs(adj, visited, arr, i)
        
    visited[s]=1
    arr.append(s)
    
    
def fun(adj, arr):
    visited = [0]*len(adj)
    
    for i in range(1, len(visited)):
        if(visited[i]==0):
            visited[i] = 1
            dfs(adj, visited, arr, i)
            
    
def main(arr):
    n, m = map(int, input().split())
    n += 1
    adj = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        adj[a].append(b)
    fun(adj, arr)
    arr.reverse()
    print(" ".join([str(ele) for ele in arr]))

if __name__ == '__main__':
    arr = []
    main(arr)
    