def MAX(x):
    if x==0:
        return 1
    elif x<0:
        return -x 
    else:
        return x+1

N = int(input())
A = [int(x) for x in input().split()]
if N==1:
    if A[0]==0:
        print(0, end=" ")
    elif A[0]>0:
        print(A[0], end=" ")
    else:
        print(-A[0]-1, end=" ")
        
elif N%2==0:
    for i in A:
        if i<0:
            print(i, end=" ")
        elif i==0:
            print(-1, end=" ")
        else:
            print(-i-1, end=" ")
else:
    B = list(set(A))
    cnt = 0
    if len(B)==1 and B[0]==0:
        print(*A, end=" ")
    else:
        for i in range(N):
            if A[i]>=0:
                A[i]= -A[i]-1
        MAX=min(A)
        for i in A:
            if i==MAX and cnt==0:
                print(-i-1, end=" ")
                cnt+=1
            else:
                print(i,end=" ")
print()



