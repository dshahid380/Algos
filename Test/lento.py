def xorlist1(A,X,K):
    d1, L1 = {}, []
    for i in range(N):
        if X>A[i]:
            xor = A[i]^X
        else:
            xor = A[i]
        if xor in d1:
            d1[xor].append(A[i])
        else:
            d1[xor] = [A[i]]
    
    #print(d1)
    L = sorted(d1.keys(), reverse=True)
    #print(L)
    for l in L:
        for i in d1[l]:
            L1.append(i)
    newlist = []

    for i in L1[:K]:
        if i^X > i:
            newlist.append(i^X) 
        else:
            newlist.append(i)

    for i in range(K,N):
            newlist.append(L1[i]) 

    return newlist

def xorlist(A,X,K):
    d1, L1 = {}, []
    for i in range(N):
        xor = A[i]^X 
        if xor in d1:
            d1[xor].append(A[i])
        else:
            d1[xor] = [A[i]]
    
    #print(d1)
    L = sorted(d1.keys(), reverse=True)
    #print(L)
    for l in L:
        for i in d1[l]:
            L1.append(i)

    newlist = []

    for i in L1[:K]:
        newlist.append(i^X) 

    for i in range(K,N):
            newlist.append(L1[i]) 

    return newlist

for _ in range(int(input())):
    N = int(input())
    A = [int(x) for x in input().split()]
    K = int(input())
    X = int(input())

    #Step 1:
    newlist1 = xorlist(A,X,K)
    newlist2 = xorlist1(A,X,K)
    print(sum(newlist1))
    print(sum(newlist2))


    # Step 2:



    




