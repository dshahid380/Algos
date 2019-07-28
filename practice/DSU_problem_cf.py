"""
Problem Link:
https://codeforces.com/contest/25/problem/D
"""
import math
from sys import stdin,stdout
from bisect import bisect_left, bisect_right
from copy import deepcopy

MAX = pow(10, 5)
inp=lambda : int(stdin.readline())
sip=lambda : stdin.readline()
mulip =lambda : map(int, stdin.readline().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())

def make_set(N):
    for i in range(1,N+1):
        d[i] = i 

def find_set(a):
    if d[a]==a:
        return a
    else:
        d[a] = find_set(d[a])
        return d[a]

def union(a, b):
    x = find_set(a)
    y = find_set(b)
    if x==y:
        arr.append([a, b])
    else:
        d[max(x, y)]= min(x,y)

N = inp()
d = {}
arr = []
par = {}
make_set(N)
for i in range(N-1):
    a, b = mulip()
    union(a, b)
#print(d)
for i in d:
    x = find_set(i)
    if x not in par:
        par[x]=x
#print(par)
l = list(par.values())
if len(l)==1 or len(arr)==0:
    print(0)
else:
    print(len(l)-1)
    for i in range(1, len(l)):
        print(*arr[i-1],l[i-1],l[i])
