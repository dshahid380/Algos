import math
import sys
from heapq import heappop
from heapq import heappush
from heapq import heapify
from bisect import insort
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
def sieve():
    prime_bool = [True]*(pow(10,6)+10)
    i = 2
    while(i*i<=pow(10,6)):
        if prime_bool[i]:
            j = i*i 
            while(j<=pow(10,6)):
                prime_bool[j] = False
                j += i 
        i += 1 

    dp = [0]*(pow(10,6)+10)
    for i in range(2,pow(10,6)+5):
        if prime_bool[i]:
            dp[i] = dp[i-1]+1
        else:
            dp[i] = dp[i-1]
    return dp 

dpp = sieve()

for i in range(inp()):
    N, K = mulip()
    print(pow(K,dpp[N],mod))


