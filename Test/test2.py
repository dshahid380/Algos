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
        return find_set(d[a])

def union(a, b):
    x = find_set(a)
    y = find_set(b)
    if x==y:
        arr.append([a, b])
    else:
        d[max(x, y)]= min(x,y)







