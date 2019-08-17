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
    
def dfs1(v):
    visited[v] = True
    print(v, end=" ")
    for i in adj[v]:
        if visited[i]==False:
            dfs1(i)

def dfs2(v):
    visited[v] = True
    for i in adj[v]:
        if visited[i]==False:
            dfs2(i)
    stack.append(v)

def get_transpose(adj):
    A = defaultdict(list)
    for i in adj:
        for j in adj[i]:
            A[j].append(i)
    return A 


for _ in range(int(input())):

    # Number of nodes and edges
    N, M = map(int, input().split())
    adj = defaultdict(list)
    visited = [False]*(N+1)
    stack = deque()
    
    for _ in range(M):
        u, v = map(int, input().split())
        add_edge(u, v)

    for i in range(N):
        if visited[i]==False:
            dfs2(i)

    adj = get_transpose(adj)
    visited = [False]*(N+1)

    while stack:
        i = stack.pop()
        if visited[i]==False:
            dfs1(i)
            print()

    


