def return_index(A,K):
    A = sorted(A)
    l, r = 0, len(A)-1
    while(l<r):
        if A[l]+A[r]==K:
            return "Yes"
        elif A[l]+A[r]>K:
            r -= 1
        else:
            l += 1
    return "No"

for _ in range(int(input())):
    N, K = map(int, input().split())
    A = [int(x) for x in input().split()]
    print(return_index(A, K))
