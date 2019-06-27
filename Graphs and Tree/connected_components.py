from collections import defaultdict

def add_edge(u, v):
    """Undirected graph adjacency list"""
    adj[u].append(v)
    adj[v].append(u)

def dfs(stack, s):
    visited[s] = True 
    stack.append(s)
    for u in adj[s]:
        if visited[u] == False:
            stack = dfs(stack, u)
    return stack

def connected_component():
    arr = []

    for i in range(1,N):
        if visited[i] == False:
            stack = []
            arr.append(dfs(stack, i))
    return arr

# Testing
N, M = map(int, input().split())
adj = defaultdict(list)
visited = [False]*(N+1)
for _ in range(M):
    u, v = map(int, input().split())
    add_edge(u, v)
arr = connected_component()

for i in arr:
    print(*i)
    
