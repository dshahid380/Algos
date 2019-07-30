"""The normal Fenwick tree can only answer sum queries
 of the type [0;r] using sum(int r), however we can 
 also answer other queries of the type [l;r] by computing
  two sums [0;r] and [0;l−1] and subtract them"""

def update(val, idx):
	while(idx < len(A)):
		tree[idx] += val
		idx = idx | (idx + 1)

def sum_upto(r):
	res = 0
	while(r >= 0):
		res += tree[r]
		r = (r & (r+1)) - 1
	return res

def query(l, r):
	return (sum_upto(r) - sum_upto(l-1)) 

def build():
	for i in range(len(A)):
		update(A[i], i)

N = int(input())
A = [int(x) for x in input().split()]
tree = [0]*N 
build()
print(tree)
update(1,4)
print(query(1,4))
print(tree)