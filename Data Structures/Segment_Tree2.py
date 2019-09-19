def count_max(a, b):
	if a[0] > b[0]:
		return a
	if b[0] > a[0]:
		return b 
	x = [a[0],a[1]+b[1]]
	return x 

def build(v, tl, tr):
	if tl==tr:
		tree[v] = [A[tl],1]
	else:
		tm = (tl+tr)//2 
		build(2*v, tl, tm)
		build(2*v+1, tm+1, tr)
		tree[v] = count_max(tree[2*v],tree[2*v+1])

def get_max(v, tl, tr, l, r):
	if l>r:
		return [-999,0]
	if l==tl and r==tr:
		return tree[v]
	tm = (tl+tr)//2
	max_pair = count_max(get_max(2*v, tl, tm, l, min(r,tm))
		                 ,get_max(2*v+1, tm+1, tr, max(l, tm+1),r))
	return max_pair

def update(v, tl, tr, pos, val):
	if tl==tr:
		tree[v] = [val, 1]
	else:
		tm = (tl+tr)//2 
		if pos <=tm:
			update(2*v, tl, tm, pos, val)
		else:
			update(2*v+1, tm+1, tr, pos, val)
		tree[v] = count_max(tree[2*v],tree[2*v+1])

for _ in range(int(input())):
	N = int(input())
	A = [int(x) for x in input().split()]
	tree = [[0,0] for i in range(4*N+2)]
	build(1,0,N-1)
	l, r = map(int, input().split())
	mx_pair = get_max(1,0, N-1, l, r)
	print(mx_pair[0],mx_pair[1])
