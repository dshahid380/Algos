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
    
def bfs(s):
    q = deque()
    q.append(s)
    color[s] = 0
    isBipartile = True
    while(len(q)>0 and isBipartile):
        u = q.popleft()
        for i in adj[u]:
            if color[i]==INF:
                color[i] = 1 - color[u]
                q.append(i)
            elif color[i]==color[u]:
                isBipartile = False
                break
    return isBipartile



for _ in range(int(input())):

    # Number of nodes and edges
    N, M = map(int, input().split())
    adj = defaultdict(list)
    color = [INF]*(N+1)

    for _ in range(M):
        u, v = map(int, input().split())
        add_edge(u, v)
    if bfs(1):
        print("The graph is bipartile")
    else:
        print("Graph is not bipartile")


