import math
from sys import stdin,stdout
from bisect import bisect_left, bisect_right
from copy import deepcopy

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
def Sum(A):
    ans = 0
    for i in range(len(A)):
        ans += A[i]*(i+1)
    return ans 


for _ in range(inp()):
    N = inp()
    A = lst()
    s = Sum(A)
    if N==1:
        print(s)
    elif N==2:
        ans = min(A)*1 + max(A)*2
        print(ans)
    else:
        avail = [False]*N
        for i in range(1, len(A)-1):
            if A[i-1] > A[i] and A[i] > A[i+1] and avail[i]==False and avail[i-1]==False:
                x = A[i-1] - A[i]
                y = A[i] - A[i+1]
                if y > x:
                    s += y
                    avail[i],avail[i+1] = True, True
                else:
                    s += x
                    avail[i],avail[i-1] = True, True

            elif A[i-1] > A[i] and A[i] < A[i+1] and avail[i-1]==False and avail[i]==False:
                s += A[i-1] - A[i]
                avail[i-1],avail[i] = True, True
            elif A[i-1] < A[i] and A[i] > A[i+1] and avail[i]==False and avail[i+1]==False:
                s += A[i] - A[i+1]
                avail[i], avail[i+1]=True, True
        print(s)

