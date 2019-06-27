from collections import defaultdict
from collections import deque
INF = 10**5

def add_edge(u, v):
    """Undirected graph adjacency list"""
    adj[u].append(v)
    adj[v].append(u)

def add_edge_directed(u, v):
    """Directed graph adjacency list"""
    adj[u].append(v)
    
def dfs(v, p=-1):
    global t 
    visited[v] = True
    tin[v]=t
    low[v]=t
    t += 1
    for to in adj[v]:
        if to==p:
            continue
        if visited[to]:
            low[v] = min(low[v], tin[to])
        else:
            dfs(to, v)
            low[v] = min(low[v], tin[to])
            if low[to] > tin[v]:
                print("Bridge",v, to)


for _ in range(int(input())):

    # Number of nodes and edges
    N, M = map(int, input().split())
    adj = defaultdict(list)
    visited = [False]*(N+1)
    tin = [-1]*(N+1)
    low = [-1]*(N+1)

    for _ in range(M):
        u, v = map(int, input().split())
        add_edge(u, v)
    t = 0
    for i in range(N):
        if visited[i]==False:
            dfs(i)
     


