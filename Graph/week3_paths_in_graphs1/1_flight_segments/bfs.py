# cook your dish here

def fun(v_to_go, adj, n, queue, end):
    count = 1
    if end in queue:
        print(count)
        return
    else:
        while len(queue)!=0:
            l = len(queue)
            count += 1
            for _ in range(l):
                x = queue.pop(0)
                if v_to_go[x]!=0:
                    v_to_go[x]=0
                    if end in adj[x]:
                        print(count)
                        return
                    queue = queue + adj[x]
                
        print('-1')

n, m = map(int,input().split())
n = n+1
edges = []
for _ in range(m):
    temp = list(map(int, input().split()))
    edges.append(temp)
start, end = map(int, input().split())

adj = [[] for _ in range(n)]

for (a, b) in edges:
    adj[a].append(b)
    adj[b].append(a)

v_to_go = [1]*n
queue = adj[start]
v_to_go[start] = 0
fun(v_to_go, adj, n, queue, end)