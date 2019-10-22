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
pw = []
for i in range(40):
  pw.append(pow(3,i))

for _ in range(inp()):
  n = inp() 
  x = n
  f = 0
  p = defautdict(int)
  while(x>0):
    for i in range(40):
      if pw[i]>x:
        x -= pw[i-1]
        p[i-1]+=1
      elif pw[i]==x:
        x -= pw[i] 
        p[i]+=1 
  for i in p:
    if p[i]>1:
      f = 1 
  if f ==0:
    print(n) 
  else: 
    cnt = 0
    l = sorted(p.keys())
    if len(l)==1:
      if l[0]==0:
        print(10)
      else:
        print(pw[l[0]]+pw[l[0]-1])
    else:
      for i in range(1,len(l)):
        cnt += l[i]-l[i-1]-1 
      if cnt==0:
        for i in p:
          if p[i]>1:
    


