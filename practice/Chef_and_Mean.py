for _ in range(int(input())):
	n = int(input())
	A = [int(x) for x in input().split()]
	sm = sum(A)
	mean = sm/n
	#A = sorted(A)
	L = []
	for i in range(n):
		if(sm-A[i])*n == sm*(n-1):
			L.append([A[i], i+1])
	if len(L)==0:
		print("Impossible")
	else:
		L = sorted(L)
		print(L[0][1])
			
			


