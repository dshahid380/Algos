def build(v, tl, tr):
	if tl == tr:
		tree[v] = A[tl]
	else:
		tm = (tl + tr)//2 
		build(2*v, tl, tm)
		build(2*v+1, tm+1, tr)
		tree[v] = tree[2*v] + tree[2*v +1]

def query(v, tl, tr, l, r):
	if l>r:
		return 0
	if l==tl and r==tr:
		return tree[v] 
	tm = (tl+tr)//2 
	sm = query(2*v, tl, tm, l, min(r, tm)) + query(2*v+1, tm+1, tr, max(l,tm+1), r)
	return sm

def update(v, tl, tr, pos, new_val):
	if tl==tr:
		tree[v] = new_val 
	else:
		tm = (tl+tr)//2 
		if pos<=tm:
			update(2*v, tl, tm, pos, new_val)
		else:
			update(2*v+1, tm+1, tr, pos, new_val)
		tree[v] = tree[2*v] + tree[2*v+1]

A = [1,2,3,4,5,6,7]
tree = [0]*(4*len(A))
build(1, 0, len(A)-1)
print("Sum in range[1..3] :",query(1,0,len(A)-1,0,2))
update(1, 0, len(A)-1, 3, 14)
print("Sum in range[1..3] :",query(1,0,len(A)-1,0,3))