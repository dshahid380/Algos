def solve(A, B, C):
	"""It will print all common elements among these three arrays
	   in linear time and in O(1) space.
	"""
	i, j, k = 0, 0, 0
	while(i < len(A) and j < len(B) and k < len(C)):
		if A[i] == B[j] and B[j] == C[k]:
			print(A[i], end=" ")
			i += 1
			j += 1
			k += 1

		elif A[i] < B[j]:
			i += 1

		elif B[j] < C[k]:
			j += 1
			
		else:
			k += 1

for _ in range(int(input())):
	A = [int(x) for x in input().split()]
	B = [int(x) for x in input().split()]
	C = [int(x) for x in input().split()]
	solve(A, B, C)
	print()
