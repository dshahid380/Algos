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
MOD = pow(10,9)+7
#-------------------------------------------------------
def modmult(a,b):
    ans = ((a%MOD)*(b%MOD))%MOD 
    return ans 

def make_list(s):
    l = []
    for i in s:
        l.append(int(i))
    return l 

def make_dict():
    s = 0
    d[0]=0
    for i in range(1,100):
        if i%11==0:
            s += i//11 
        d[i]=s 

def make_product():
    product = 1
    for i in range(1,200005):
        product = (product*10)%MOD
        pw[i] = product

def make_mult():
    multi[3]=110
    for i in range(4,100100):
        multi[i] = modmult(multi[i-1],100) + pw[i-2]
        multi[i] %=MOD 

def cal_minus(num, p):
    """num is a single digit and p is exponent to 10."""
    if p==0:
        return d[num]
    elif p==1:
        return d[num*10]
    elif p==2:
        a = (45*pow(num,2) + ((num*(num-1))//2)*10)%MOD
        return a 
    else:
        a = modmult(45*pow(num,2),multi[p]) + modmult(((num*(num-1))//2),pw[p-1]) 
        return a 

def minus_upto(l):
    """l is a list of digits"""
    n = len(l)
    repeat = 0
    sm = cal_minus(l[0], n-1)
    for i in range(1,n):
        cal = cal_minus(l[i],n-1-i)
        if l[i]>l[i-1]:
            sm += modmult(l[i-1],modmult(pw[n-1-i],pw[n-i-1])) + cal + modmult(repeat,l[i]*pw[n-i-1])
        elif l[i]<l[i-1]:
            sm += cal + modmult(repeat,l[i]*pw[n-i-1])
        elif l[i]==l[i-1]:
            sm += cal + modmult(repeat,l[i]*pw[n-i-1])
            repeat += modmult(l[i],pw[n-i-1])
            repeat = repeat%MOD 
    sm += repeat
    sm = sm % MOD 
    return sm 
               
d = {}
pw = [1]*200005
multi = [1]*100100
make_dict()
make_product()
make_mult()

for _ in range(int(input())):
    nl, L = mulip()
    nr, R = mulip()
    L = L-1
    l = make_list(str(L))
    r = make_list(str(R))
    sumL = ((L%MOD)*((1+L)%MOD))%MOD 
    sumL = (sumL * (pow(2,MOD-2,MOD)))%MOD
    sumL = sumL - minus_upto(l)%MOD
    sumR = ((R%MOD)*((1+R)%MOD))%MOD 
    sumR = (sumR * (pow(2,MOD-2,MOD)))%MOD
    sumR = sumR - minus_upto(r)%MOD 
    print((sumR-sumL)%MOD) 

