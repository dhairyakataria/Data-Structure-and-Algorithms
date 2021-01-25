import math

def minCost(adj, weights, start, destination):
    cost = [math.inf]*len(adj)
    visited = [0]*len(adj)
    cost[start] = 0
    visited[start] = 1
    queue = adj[start]
    arr = []
    
    for j in range(len(adj[start])):
        arr.append( (weights[start][j], adj[start][j]) )
    arr = sorted(arr, key=lambda x:x[0], reverse=True)
    
    
    while (len(arr)!=0):
        x = arr.pop(-1)
        ele = x[1]
        if(visited[ele]==1):
            continue
        visited[ele] = 1
        cost[ele] = x[0]
        
        for j in range(len(adj[ele])):
            if visited[adj[ele][j]] == 1:
                continue
            
            dis = cost[ele] + weights[ele][j]
            if cost[adj[ele][j]] > dis:
                cost[adj[ele][j]] = dis
                arr.append( (dis, adj[ele][j]) )
            
        arr = sorted(arr, key=lambda x:x[0], reverse=True)
        
    if cost[destination] == math.inf:
        return -1
    else:
        return cost[destination]
            
    
def main():
    n, m = map(int, input().split())
    n += 1
    adj = [[] for _ in range(n)]
    weights = [[] for _ in range(n)]
    for _ in range(m):
        a, b, c = map(int, input().split())
        adj[a].append(b)
        weights[a].append(c)
    
    start, destination = map(int, input().split())
    print(minCost(adj, weights, start, destination))

if __name__ == '__main__':
    main()
    