from math import gcd, ceil 
from collections import defaultdict, deque
from sys import stdin,stdout
from bisect import bisect_left, bisect_right
from copy import deepcopy

inp=lambda : int(stdin.readline())
sip=lambda : stdin.readline()
mulip =lambda : map(int, stdin.readline().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())
M = pow(10,9)+7
#-----------------------------------------------------
for _ in range(inp()):
	n,r = mulip()
	A = lst()
	A = sorted(A)
	A = list(set(A))
	#print(*A)
	L,R,k=0,len(A)-1,1
	r1 = r 
	while(L<R):
		if L-R==1:
			k+=1
			break
		if r1>=A[L]:
			L+=1
		else:
			R-=1
			r1+=r 
			k+=1
	print(k)



