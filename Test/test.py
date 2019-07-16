import math
import sys
from heapq import heappop
from heapq import heappush
from heapq import heapify
from bisect import insort
from sys import stdin,stdout
from collections import defaultdict
M=10**9+7

def isprime(n) :  
    if(n<=1) : 
       return False
    if(n<=3) : 
       return True
    if(n%2==0 or n%3==0) : 
       return False
    i=5
    while(i*i<=n) : 
        if(n%i==0 or n%(i+2)==0) : 
           return False
        i=i+6
    return True
def freq(l): #return freq disctionary   
    f = {} 
    for i in l: 
        if (i in f): 
            f[i] += 1
        else:
          f[i] = 1
    return f

inp=lambda : int(stdin.readline())
sip=lambda : input()
mulip =lambda : map(int,input().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())
arr2d= lambda x: [[int(j) for j in input().split()] for i in range(x)]
odds = lambda l: len(list(filter(lambda x: x%2!=0, l)))
evens = lambda l: len(list(filter(lambda x: x%2==0, l)))
#-------------------------------------------------------

def solve(A, x):
  l, r = 0, len(A)-1
  diff = sys.maxsize 
  #val1, val2 = 0, 0
  while(l < r):
     if abs(A[l] + A[r] - x) < diff:
        val1, val2 = l, r 
        diff = abs(A[l] + A[r] - x)

     if A[l] + A[r] > x:
        r -= 1
     else:
        l += 1
  return (A[val1], A[val2])

for _ in range(int(input())):
   x = int(input())
   A = [int(x) for x in input().split()]
   print(*solve(A, x))


    



                



    




    

