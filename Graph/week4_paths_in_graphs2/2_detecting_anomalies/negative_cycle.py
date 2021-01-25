import math

def negCycle(adj, V, E):
    cost = [math.inf]*(V+1)
    cost[1] = 0
    
    for i in range(V-1):
        for j in range(E):
            u = adj[j][0]
            v = adj[j][1]
            w = adj[j][2]
            dis = cost[u] + w
            if cost[v] > dis:
                cost[v] = dis
    
    for j in range(E):
        u = adj[j][0]
        v = adj[j][1]
        w = adj[j][2]
        dis = cost[u] + w
        if cost[v] > dis:
            return 1
    return 0
    
    
    
def main():
    n, m = map(int, input().split())
    adj = []
    weights = [[] for _ in range(n)]
    for _ in range(m):
        ls = list(map(int, input().split()))
        adj.append(ls)
        
    
    print(negCycle(adj, n, m))

if __name__ == '__main__':
    main()
    