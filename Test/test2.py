import math
from collections import defaultdict, deque
from sys import stdin,stdout
from bisect import bisect_left, bisect_right
from copy import deepcopy

inp=lambda : int(stdin.readline())
sip=lambda : stdin.readline()
mulip =lambda : map(int, stdin.readline().split())
lst=lambda : list(map(float,stdin.readline().split()))
slst=lambda: list(sip())
M = pow(10,9)+7
#-------------------------------------------------------
for _ in range(inp()):
    N = inp()
    f1,ans,f2,f3,k = 0,0,0,0,0
    K = lst()
    C = lst()
    numK = list(set(K))
    for i in range(N):
        f2 += K[i]*C[i]
        k += 1/K[i]
        #print("f2 :",f2, "k :",k)

    f3 = f2/k 
    #print("f3 :",f3)
    for i in range(N):
        temp = f3/(pow(K[i],2))
        #print("temp :", temp)
        if(temp<0):
            print(-1)
            f1 = 1
            break
        
        ans+=pow(temp,0.5)
        #print("ans :",ans)
        

    if(f1!=1):
        print(ans, end=" ")
        for i in range(N):
            temp = f3/pow(K[i],2)
            temp-=C[i]
            print(temp, end=" ")
            K[i],C[i]=0,0
        print()




            




    
