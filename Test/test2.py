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
from math import log,ceil 
n,b = mulip()
x = b*b*int(log(2*n+1))
ans = 0 
tmp = 0
for i in range(1,n+1):
    ans += (b*b)//i
    tmp += 1/i 
tmp = b*b*tmp 
print("Actual :",ans)
print("calculated1 :",int(x))
print("calculated2 :",int(tmp))













