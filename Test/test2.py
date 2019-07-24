import math
from sys import stdin,stdout, maxsize
from bisect import bisect_left, bisect_right

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
sip=lambda : stdin.readline()
mulip =lambda : map(int, stdin.readline().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())
#-------------------------------------------------------

def find_max_cost(a,size, k, m): 
  
    max_so_far = -maxsize - 1
    max_ending_here = 0
    start = 0
    end = 0
    s = 0
  
    for i in range(0,size): 
  
        max_ending_here += a[i] 
  
        if max_so_far < max_ending_here: 
            max_so_far = max_ending_here 
            start = s 
            end = i 
  
        if max_ending_here < 0: 
            max_ending_here = 0
            s = i+1
  
    ans = max_so_far - k*math.ceil((end-start+1)/m) 
    return ans
    

n, m, k = mulip()
A = lst()
print(find_max_cost(A, n, k, m))







  
