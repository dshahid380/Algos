from collections import defaultdict

def add_edge(u, v):
    """Directed graph adjacency list"""
    adj[u].append(v)
    

def dfs_ts(s):
    visited[s] = True
    for i in adj[s]:
        if visited[i] == False:
            dfs_ts(i)
    arr.append(s)

for _ in range(int(input())):

    # Number of nodes and edges
    N, M = map(int, input().split())
    adj = defaultdict(list)
    visited = [False]*(N+1)
    arr = []

    for _ in range(M):
        u, v = map(int, input().split())
        add_edge(u, v)

    for i in range(N):
        if visited[i] == False:
             dfs_ts(i)

    print(*arr[::-1])

