import sys
from heapq import heappop
from heapq import heappush
from heapq import heapify
from bisect import insort
from bisect import bisect_right
from bisect import bisect_left
from sys import stdin,stdout
from collections import defaultdict

inp=lambda : int(stdin.readline())
sip=lambda : input()
mulip =lambda : map(int,input().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())
arr2d= lambda x: [[int(j) for j in input().split()] for i in range(x)]
odds = lambda l: len(list(filter(lambda x: x%2!=0, l)))
evens = lambda l: len(list(filter(lambda x: x%2==0, l)))
mod = pow(10,9)+7
#-------------------------------------------------------
d = {"&":1, "|":2, "^":3}

def op(a,o,b):
	if o==1:
		return a&b 
	elif o==2:
		return a|b 
	else:
		return a^b 

def solve(l):
	#print(*l)
	if len(l)==1:
		return int(l[0])
		
	if len(l)==3:
		return op(int(l[0]),d[l[1]],int(l[2]))
	
	ans = 0 
	for i in range(len(l)):
		if i%2==1:
			x1 = op(solve(l[:i]),d[l[i]],solve(l[i+1:]))
			ans = max(ans,x1)
			print(ans,":",*l)
	return ans

for i in range(inp()):
	s = list(input())
	L = []
	tmp = ""
	for i in s:
		if i not in d:
			tmp+=i 
		else:
			L.append(tmp)
			L.append(i)
			tmp=""
	if tmp!="":
		L.append(tmp)

	print(solve(L))
	#print(*l)




	
















