import numpy
import math
from sys import stdin,stdout
from bisect import bisect_left, bisect_right
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

def Freq(l): #return freq disctionary   
    f = {} 
    for i in l: 
        if (i in f): 
            f[i] += 1
        else:
          f[i] = 1
    return f

inp=lambda : int(stdin.readline())
sip=lambda : stdin.readline()
mulip =lambda : map(int, stdin.readline().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())
#-------------------------------------------------------
for _ in range(inp()):
    S = slst()
    one = [0]*(len(S))
    zero = [0]*(len(S))
    cnt=0
    cnt2 = 0
    for i in range(len(S)):
        if S[i]=="1":
            cnt+=1
        else:
            cnt2+=1
        one[i]=cnt
    
    for i in range(len(S)):
        if S[i]=="0":
            cnt2+=1
        zero[i]=cnt2
    cnt=0
    for i in range(1, len(S)+1):
  
            if pow(j, 2) + j > i:
                break
            if i-j*j-j-1 < 0:   
                cnt1= one[i-1]
                cnt0 = zero[i-1]
            else:
                cnt1= one[i-1] - one[i-j*j-j-1]
                cnt0 = zero[i-1] - zero[i-j*j-j-1]
            if pow(cnt1, 2) ==cnt0:
                cnt += 1
            j += 1
    stdout.write(str(cnt)+"\n")
  
