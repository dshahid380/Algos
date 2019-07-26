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
#-------------------------------------------------------

def check_composite(n, a, d, s):
  x = pow(a, d, n)
  if x==1 or x==n-1:
    return False
  for r in range(1, s):
    x = x * x % n
    if x==n-1:
      return False
  return True

def isprime(n):
  """Miller-Rabin Algorithm for checking a number is prime or not
  """  
  if n<2:
    return False
  r = 0 
  d = n-1
  while((d&1)==0):
    d >>=1
    r += 1
  base = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
  for a in base:
    if n==a:
      return True
    if check_composite(n, a, d, r):
      return False
  return True


N, Q = mulip()
A = lst()
M = [0]*(N+1)
for i in range(N):
    if A[i]==3 or A[i]==4 or A[i]==6:
        M[i+1] = 1
for i in range(1,N+1):
    M[i] += M[i-1]

for i in range(Q):
    l, r = mulip()
    print(M[r]-M[l-1])
