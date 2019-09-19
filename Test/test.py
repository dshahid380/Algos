import math
import sys
from heapq import heappop
from heapq import heappush
from heapq import heapify
from bisect import insort
from bisect import bisect_left
from bisect import bisect_right
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
def sieve(n):
    prime_bool = [True]*(n+1)
    i = 2
    while(i*i<=n):
        if prime_bool[i]:
            j = i*i 
            while(j<=n):
                prime_bool[j] = False
                j += i 
        i += 1 

    primes = {}
    for i in range(2,1+n):
        if prime_bool[i]:
            primes[i]=i 

    return primes
MAX = 1000006
p = sieve(MAX)
count = [0]*MAX

for i in range(2,1000006):
    if i in p:
        count[i] = count[i-1]+1
    else:
        count[i]=count[i-1]
    
for _ in range(inp()):
    N = inp()
    if N==1:
        print(0)
    elif N==2 or N==3:
        print(1)
    elif N%2==0:
        print(count[N//2])
    else:
        print(count[N]-1)

        
        



