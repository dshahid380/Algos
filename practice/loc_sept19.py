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
def degree(n,m):
    l = n-1
    r = (n*(n+1))//2 
    if n==1:
        if m==0:
             print(0)
        elif m==1:
             print(1)
        else:
             print(-1)
    elif n==2:
        if m==1:
            print(1)
        elif m==2 or m==3:
            print(2)
        else:
            print(-1)
    elif m<l or m>r:
        print(-1)
    else:
        if m <= n+1:
            ans = 2
        elif m > n+1 and m<=2*n:
            ans = 3 
        else:
            tmp = m - 2*n 
            if n%2==0:
                ans = math.ceil(tmp/(n//2)) + 3 
            else:
                t = math.ceil(tmp/n)
                ans = 2*math.ceil(tmp/n) + 2 
                ans1 = m - (n*(t+1))
                if ans1 < n/2:
                    pass 
                else:
                    ans += 1
        print(ans) 

for _ in range(inp()):
    n, m = mulip()
    degree(n,m) 


