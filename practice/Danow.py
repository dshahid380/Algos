"""Problem Link 
   https://www.codechef.com/problems/DANOW
"""
def build(X):
	M = [0, X[0]]
	for i in range(1,len(X)):
		X[i] += X[i-1]
		M.append(X[i])
	return M

def query(a, b):
	S = M[b] - M[a-1]
	return S 

N, Q = map(int, input().split())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
comb = []
for i in range(N):
	comb.append(A[i]*B[i])
	#print(A[i],"*", B[i], A[i]*B[i])

#print("Comb", comb)
M = build(comb)

#print("Comb", comb)
#print("M", M)

for _ in range(Q):
	x, y = map(int, input().split())
	print(query(x, y))

