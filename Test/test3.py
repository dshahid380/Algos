import math
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
#-------------------------------------------------------
def find(v):
	
	
       



for _ in range(inp()):
	N = inp()
	p1, p2, p3 = mulip()
	adj = defaultdict(list)
	for i in range(N-1):
		u, v = mulip()
		adj[v].append(u)
		adj[u].append(v)
	flag=0
	for i in adj:
		if len(adj[i])==N-1:
			flag=1
			center=i 
			break

	if flag==1:
		if p2==1:
			n = N- center
			ans = n*(n-1)
			print(ans>>1)
		elif p2==2:
			n = N - center
			n1 = center - 1
			print(n*n1)
		else:
			n1 = center - 1
			ans = n1*(n1-1)
			print(ans>>1)
	else:
		print(N//2)
