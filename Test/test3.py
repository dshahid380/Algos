from collections import defaultdict
for t in range(int(input())):
    n = int(input())
    m = []
    c, r, k = 0, 0, 0
    for i in range(n):
        d = defaultdict(int)
        l = [int(x) for x in input().split()]
        for i in l:
            d[i] += 1
        for i in d:
            if d[i]>1:
                c+=1
                break
        m.append(l)
    for j in range(n):
        d = defaultdict(int)
        for i in range(n):
            d[m[i][j]]+=1
            if i==j:
                k+=m[i][j]
        for i in d:
            if d[i]>1:
                r+=1
                break
    print("case #"+str(t)+":",k,r,c)
        
            
    
        