from collections import defaultdict

def make_set(N):
	for i in range(1,N+1):
		d[i] = i 

def find_set(a):
	"""Path compression is applied"""

	if d[a] == a:
		return a
	else:
		d[a] = find_set(d[a])
		return d[a]

def union(a, b):
	a = find_set(a)
	b = find_set(b)
	if a!=b:
		d[b] = a
	
def main():
    """ N is the number of vertices and M is number of 
    edges. Task is to find how many connected components
    are present in the given undirected graph."""
	N, M = int(input())
	d = defaultdict(int)
    for _ in range(M):
    	a, b = map(int, input().split())
    	union(a, b)

    # Check how many parents exits ?
    parents = []
    for i in d:
    	p = find_set(i)
    	parents.append(p)
    print(len(parents))

if __name__ == '__main__':
	main()


	
