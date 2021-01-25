# cook your dish here

def fun(v_to_go, adj, n):
    arr = [-1]*n
    
    temp = 0
    for i in range(1, n):
        if(v_to_go[i]==1):
            v_to_go[i]=0
            queue = adj[i]
            arr[i] = temp
        while len(queue)!=0:
            temp += 1
            temp = temp%2
            l = len(queue)
            
            for _ in range(l):
                x = queue.pop(0)
                if v_to_go[x]==1:
                    v_to_go[x]=0
                    queue = queue + adj[x]
                    if arr[x]==-1:
                        arr[x] = temp
                if(arr[x]!=-1 and arr[x]!=temp):
                    print('0')
                    return
            
    print('1')
    return
            


n, m = map(int,input().split())
n = n+1
edges = []
for _ in range(m):
    temp = list(map(int, input().split()))
    edges.append(temp)

adj = [[] for _ in range(n)]

for (a, b) in edges:
    adj[a].append(b)
    adj[b].append(a)

v_to_go = [1]*n
fun(v_to_go, adj, n)