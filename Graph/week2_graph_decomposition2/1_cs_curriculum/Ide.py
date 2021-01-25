def dfs(adj, stack, visited, x):
    visited[x] = 1
    stack[x] = 1
    for i in adj[x]:
        if visited[i]==0 and dfs(adj, stack, visited, i)==1:
            return 1
        if stack[i]==1:
                return 1
    stack[x] = 0
    
    return 0
    
    
def fun(adj):
    stack = [0]*len(adj)
    visited = [0]*len(adj)
    
    for i in range(1, len(adj)):
        if visited[i]==0:
            if dfs(adj, stack, visited, i)==1:
                return 1
            
    return 0
    
    
def main():
    n, m = map(int, input().split())
    n += 1
    adj = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        adj[a].append(b)
    print(fun(adj))

if __name__ == '__main__':
    main()
    