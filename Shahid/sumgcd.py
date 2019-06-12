from math import gcd
for _ in range(int(input())):
    N = int(input())
    A = [int(x) for x in input().split()]
    ans = []

    #Base Cases :
    if len(A) == 2:
        print(A[0] + A[1])

    elif len(set(A)) == 1:
        print(2 * A[0])

    elif len(set(A)) == 2:
        print(min(A) + max(A))
    else:

        #Case 1: 
        B = sorted(A)
        X = gcd(B[0],B[1])
        for i in range(2, N):
            if B[i] != B[N-1]:
                X = gcd(X,B[i]) 
        ans.append(B[N-1] + X)

        #Case 2:
        copm = 0
        for i in range(N-1):
            if gcd(B[i],B[i+1])==1:
               copm += 1
               num = B[i]       
               #num2 = B[i+1]
        #print("Num :", num)

        if copm==2 or copm==1:
            X = gcd(B[0],B[1])
            #print("X",X)

            for i in range(2,N):
                if B[i]!=num:
                    X = gcd(X,B[i])
            ans.append(X+num) 
        print(max(ans))


        