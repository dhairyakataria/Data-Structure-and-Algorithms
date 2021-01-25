# cook your dish here
#Uses python3
stack = []
count = 0

def dfs(x, n, adj, v_to_go):
    #print(x)
    v_to_go[x] = 0
    for i in adj[x]:
        if check_stack[i]==0:
            continue
        if(v_to_go[i]==1):
            #if(len(adj[i]) != 0):
            dfs(i, n, adj, v_to_go)
    stack.append(x)
    check_stack[x] = 0
    
    
def fun(n, adj, v_to_go):
    for i in range(1, n):
        if(v_to_go[i]==1):
            dfs(i, n, adj, v_to_go)
    return 0



if __name__ == '__main__':
    n, m = map(int,input().split())
    n = n+1
    edges = []
    for _ in range(m):
        temp = list(map(int,input().split()))
        edges.append(temp)
        
        
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a].append(b)
    
    for (b, a) in edges:
        adj[a].append(b)
    
    v_to_go = [1]*n
    check_stack = [1]*n
    fun(n, adj, v_to_go)
    
    stack.reverse()
    #print("stack=", stack)
    v_to_go_2 = [1]*n
    fun_2(n, reverse_adj, v_to_go_2)
    
    print(count)