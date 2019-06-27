from collections import deque 
class Graph(object):
    """class Graph contains all the properties of node which
    requires during breadth first searching"""
    def __init__(self, color="WHITE",node=-1, d=-1, pi=None, data=-1):
        self.color = color
        self.node = node
        self.d = d 
        self.pi = pi
        self.data = data
        
def add_directed_edge(u, v):
    """As name suggest it is used to make adjacency list of
    dictionary when there is directed graph"""
    if u in Adj:
        Adj[u].append(v)
    else:
        Adj[u] = [v]

def add_undirected_edge(u, v):
    """As name suggest it is used to make adjacency list of
    dictionary when there is undirected graph"""
    if u in Adj:
         Adj[u].append(v)
    else:
        Adj[u] = [v]
    if v in Adj:
        Adj[v].append(u)
    else:
        Adj[v] = [u]

def Initialization(A, N):
    """Returns the unvisited graph with some initialization"""
    Node = []
    for i in range(1,N+1):
        Node.append(Graph(node=i,data=A[i-1]))
    return Node 

def BFS(A, N):
    """This is the main class of BFS because it returns the processed
    node which in turn can be used to do other operations"""
    Node = Initialization(A, N)
    Node[0].color = "GRAY"
    Node[0].d = 0
    Q = deque()
    Q.append(Node[0])

    while(len(Q)!=0):
        U = Q.popleft()
        for i in Adj[U.node]:
            if Node[i-1].color == "WHITE":
                Node[i-1].color = "GRAY"
                Node[i-1].d = U.d + 1
                Node[i-1].pi = U
                Q.append(Node[i-1])
        U.color = "BLACK" 
    return Node 

# Test cases
for _ in range(int(input())):
    N = int(input())

    # Taking node data as in array
    A = [int(x) for x in input().split()]

    # Initialized adjancency list as dictionary
    Adj = {}

    # In case of Tree
    for _ in range(N-1):
        u, v = map(int, input().split())
        add_undirected_edge(u, v)

    Node = BFS(A, N)

    # Print distances of all nodes
    for i in range(N):
        print(Node[i].d)





