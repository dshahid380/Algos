from bisect import bisect_right

def odds(A):
	l = []
	for i in range(len(A)):
		if A[i]%2!=0:
			l.append(i)
	return l

def evens(A):
	l = []
	for i in range(len(A)):
		if A[i]%2==0:
			l.append(i+1)
	return l

def no_of_pairs(A):
	odd = odds(A)
	even = evens(A)
	#print(odd)
	#print(even)
	i, j, temp = 0, 0, 0
	total = 0
	
	for i in range(len(odd)):
		total += bisect_right(even, odd[i], 0, len(even))
		#print(bisect_right(even, odd[i], 0, len(even)))
	
	return total

for _ in range(int(input())):
	n = int(input())
	A = [int(x) for x in input().split()]
	print(no_of_pairs(A))
