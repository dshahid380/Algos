from math import gcd
for _ in range(int(input())):
    N = int(input())
    A = [int(x) for x in input().split()]
    A = list(set(A))
    N = len(A)
    ans = []
    B = sorted(A)

    #Base Cases :
    if len(A) == 2:
        print(A[0] + A[1])

    elif len(A) == 1:
        print(2 * A[0])

    elif len(B)==3:
        ans.append(gcd(B[0], B[1]) + B[2])
        ans.append(gcd(B[0], B[2]) + B[1])
        ans.append(gcd(B[1], B[2]) + B[0])
        print(max(ans))
        
    else:

        #Case 1: 
        X = gcd(B[0],B[1])
        for i in range(0, N):
            if B[i] != B[N-1]:
                X = gcd(X,B[i]) 
        #ans.append(B[N-1] + X)

        #Case 2:
        copm = 0
        for i in range(N-1):
            if gcd(B[i],B[i+1])==1:
               copm += 1
               num = B[i]       
               #num2 = B[i+1]
        #print("Num :", num)

        if copm>=1:
            X = gcd(B[0],B[1])
            #print("X",X)

            for i in range(0,N):
                if B[i]!=num:
                    X = gcd(X,B[i])
            #ans.append(X+num)

        #Case 3:
        L= []
        X = gcd(B[0],B[1])
        for i in range(0,N-1):
            if gcd(X,B[i])==1 and gcd(B[i], B[i+1])==1:
                X = gcd(X, B[i+1])
                L.append(B[i])
        if len(L)==1 or len(set(L))==1:
            ans.append(X+L[0])
        elif len(L)>1:
            pass
            #ans.append(max(L)+1)

        
        #Case 5:
        X1 = gcd(B[0],B[N-1])
        for i in range(1,N-2):
            X1 = gcd(X1, B[i]) 
        ans.append(B[N-2]+X1)

        X1 = gcd(B[0],B[N-2])
        for i in range(1,N-2):
            X1 = gcd(X1, B[i]) 
        ans.append(B[N-1]+X1)

        print(max(ans))
                



