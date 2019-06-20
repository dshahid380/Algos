from collections import OrderedDict
from random import randint
def count_arr(s1):
    l1, cnt = [], 0
    for i in range(1,len(s1)):
        if s1[i]==s1[i-1]:
            cnt+=1
        else:
            l1.append([cnt,ord(s1[i-1])])
            cnt = 1
    l1.append([cnt, ord(s1[-1])])
    return l1

def solve(s1, s2):
    l1 = count_arr(s1)
    l2 = count_arr(s2)
    cnt = 0
    if len(l1)>len(l2):
        return False
    for i in range(len(l1)):
        if l1[i][0]<=l2[i][0] and l1[i][1]==l2[i][1]:
            continue
        else:
            cnt += 1
            break 

    if cnt == 0:
        return True
    else:
        return False

def polycarp(s1,s2):
    d1, d2 = OrderedDict(), OrderedDict()
    for i in s1:
        if i in d1:
            d1[i]+=1
        else:
            d1[i]=1
    for i in s2:
        if i in d2:
            d2[i]+=1
        else:
            d2[i]=1
    if len(d1)!=len(d2):
        return "NO"
    elif len(s1)>len(s2):
        return "NO"
    elif s1==s2:
        return "YES"
    else:
        l = list(d1.keys())
        cnt = 0
        for i in l:
            if i not in d2:
                cnt += 1
                break
            
        if solve(s1,s2):
             #print(solve(s1, s2))
             pass
        else:
            cnt += 1
    
        if cnt==0:
            return "YES"
        else:
            return "NO"
def solve2(a, b):
    i=0
    for j in range(len(b)):
        if j and i < len(a) - 1 and a[i+1] == b[j]:
            i += 1
        elif b[j] != a[i]:
            return False
    return i == len(a) - 1
    
for _ in range(100000):
    x1 = randint(1,10)
    x2 = x1 + randint(1,10)
    s1, s2 = "", ""
    for _ in range(x1):
        s1 += chr(randint(97,98))
    for _ in range(x2):
        s2 += chr(randint(97,99))
    if solve2(s1, s2) and polycarp(s1, s2)=="NO":
        print(s1)
        print(s2)
        print("===============================")
    



        