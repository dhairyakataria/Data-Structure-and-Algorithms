def fun(adj):
    queue = []
    count = 0
    visited = [0]*len(adj)
    
    for i in range(1, len(visited)):
        if visited[i]==0:
            queue = adj[i]
            count += 1
            while len(queue)!=0:
                x = queue.pop(0)
                if visited[x] == 0:
                    visited[x] = 1
                    queue += adj[x]
    return count
    
def main():
    n, m = map(int, input().split())
    n += 1
    adj = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)
    
    print(fun(adj))

if __name__ == '__main__':
    main()
    