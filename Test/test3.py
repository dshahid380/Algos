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
from collections import defaultdict
def fresh_job(A, i):
    for j in range(i-1,-1,-1):
        if A[j][0] <= A[i][1]:
            return j 
    return -1

def maxEvents(arrival, duration):
    A = []
    n = len(arrival)
    for i in range(n):
        start = arrival[i]
        finish = arrival[i] + duration[i]
        A.append([finish,start,1])

    A = sorted(A)
    dp = [0]*(n+1)
    dp[0] = 1
    for i in range(1,n):
        cnt = 1
        l = fresh_job(A, i)
        if(l!=-1):
             cnt += dp[l]
        dp[i] = max(cnt, dp[i-1])
    res = dp[n-1]
    return res 


for _ in range(inp()):
    n = inp()
    arrival = lst()
    duration = lst()
    print(maxEvents(arrival, duration))
    