import numpy
import math
from sys import stdin,stdout
from bisect import bisect_left, bisect_right
M=10**9+7
def pnt(x):
  stdout.write(str(x)+"\n")
def pnt(x,end=" "):
  stdout.write(str(x)+end)
def gcd(a,b):
   if(b==0): 
      return a 
   return gcd(b,a%b) 
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
def Freq(l): #return freq disctionary   
    f = {} 
    for i in l: 
        if (i in f): 
            f[i] += 1
        else:
          f[i] = 1
    return f
def MODexp(x,n,M):
  if n==0:
    return 1
  elif n%2==0:
    y=MODexp(x,n//2,M)
    return (y*y)%M
  else:
    return((x%M)*MODexp(x,n-1,M))%M

inp=lambda : int(stdin.readline())
sip=lambda : stdin.readline()
mulip =lambda : map(int, stdin.readline().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())
#-------------------------------------------------------
for _ in range(inp()):
  N,M=mulip()
  H=lst()
  C=lst()
  col=set()
  i,c=N-1,0
  while(i>=0):
    if H[i]>c:
       c=H[i]
       col.add(C[i])
    i-=1
  pnt(len(col))
