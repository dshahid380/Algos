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
def find(a):
    if par[a]==a:
        return a
    else:
        par[a] = find(par[a])
        return par[a]

for _ in range(int(input())):
    N = inp()
    s = lst()
    par = [int(x) for x in range(N)]
    Q = inp()
    for _ in range(Q):
        q = lst()
        if len(q)==3:
            a = find(q[1]-1)
            b = find(q[2]-1)
            if a==b:
               print("Invalid query!")
            elif s[a] > s[b]:
                par[b] = a 
            elif s[a] < s[b]:
                par[a] = b 
               
        else:
            print(find(q[1]-1)+1)




