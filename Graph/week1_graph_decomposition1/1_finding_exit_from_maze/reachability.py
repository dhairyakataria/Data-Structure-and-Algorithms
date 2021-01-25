def fun(adj, start, destination):
    queue = adj[start]
    if destination in queue:
        return 1
    visited = [0]*n
    visited[start] = 1
    
    while len(queue)!=0:
        x = queue.pop(0)
        if visited[x] == 0:
            visited[x] = 1
            if destination in adj[x]:
                return 1
            else:
                queue += adj[x]
    return 0

if __name__ == '__main__':
    n, m = map(int, input().split())
    n += 1
    adj = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)
    start, destination = map(int, input().split())
    
    print(fun(adj, start, destination))