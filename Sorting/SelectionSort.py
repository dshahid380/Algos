def selectionSort(A):
	for i in range(len(A)):
		minpos = i 
		for j in range(minpos+1,len(A)):
			if A[j] < A[minpos]:
				minpos = j 
		temp = A[i]
		A[i] = A[minpos]
		A[minpos] = temp
	return A

for _ in range(int(input())):
	A = [int(x) for x in input().split()]
	print(*selectionSort(A))
