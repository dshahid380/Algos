def LIS(A):
	d = [1]*(len(A))
	p = [-1]*len(A)
	for i in range(len(A)):
		for j in range(i):
			if A[j] < A[i] and d[i]<d[j]+1:
				d[i] = d[j] + 1 
				p[i] = j
	
	mx = max(d)
	pos = A.index(mx)
	subseq = []
	while(pos!=-1):
		subseq.append(A[pos])
		pos = p[pos]
	return subseq[::-1]

A = [1,2,3,4,0,1,2]
print(LIS(A))