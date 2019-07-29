def find(a):
    if a==parent[a]:
        return a
    return find(parent[a])

def union(u, v):
    parent[v] = u 

# Number of jobs
N = int(input())

# job deadline
deadlines = [int(x) for x in input().split()]

# Profits 
profits = [int(x) for x in input().split()] 
A = []
for i in range(N):
    A.append([profits[i], deadlines[i]])
A = sorted(A, reverse=True)

maxx = max(deadlines)
parent = [int(x) for x in range(maxx+1)]

ans = []
for i in range(N):
    available = find(A[i][1])
    if available > 0:
        union(available-1, available)
        ans.append(A[i][0])
print(*ans)


