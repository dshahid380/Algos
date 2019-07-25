import math
from sys import stdin,stdout
from bisect import bisect_left, bisect_right

def isprime(n):  
    if(n<=1): 
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

MAX = pow(10, 5)
inp=lambda : int(stdin.readline())
sip=lambda : stdin.readline()
mulip =lambda : map(int, stdin.readline().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())
#-------------------------------------------------------
for _ in range(inp()):
    n = inp()
    maxx, maxy, minx, miny = MAX, MAX, -MAX, -MAX
    for _ in range(n):
        x, y, f1, f2, f3, f4 = mulip()
        if f2==0:
            maxy = min(maxy, y)
        if f4==0:
            miny = max(miny, y)
        if f3==0:
            maxx = min(maxx, x)
        if f1==0:
            minx = max(minx, x)
    if minx <= maxx and miny <= maxy:
        print(1,minx,miny)
    else:
        print(0)


    







  

  