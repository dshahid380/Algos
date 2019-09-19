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
for _ in range(inp()):
    R, C, K = mulip()
    A = arr2d(R)
    dp = [[0]*(C) for i in range(R)]
    for i in range(R):
    	for j in range(C):
    		if i==0:
    			dp[i][j]=A[i][j]
    		if i-1-K<0:
    			if i-1>=0 and j-1>=0 and j+1<R:
    				dp[i][j] = max(dp[i-1][j-1],dp[i-1][j+1])+A[i][j]
    			elif i-1>=0 and j-1>=0 and j+1>=R:
    				dp[i][j] = dp[i-1][j-1] + A[i][j]
    			elif i-1>=0 and j-1<0 and j+1<R:
    				dp[i][j] = dp[i-1][j+1] + A[i][j]
    		else:
    			if j-1>=0 and j+1<R:
    				dp[i][j] = max(max(dp[i-1][j-1],dp[i-1][j+1]),max(dp[i-K-1][j-1],dp[i-K-1][j+1])) +A[i][j]
    			elif j-1>=0 and j+1>=R:
    				dp[i][j] = max(dp[i-1][j-1],dp[i-K-1][j-1]) + A[i][j]
    			elif j-1<0 and j+1<R:
    				dp[i][j] = max(dp[i-1][j+1],dp[i-K-1][j+1]) + A[i][j]
    
    print(max(dp[R-1]))