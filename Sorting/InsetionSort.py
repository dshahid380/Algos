def insertionSort(A):
    for i in range(1, len(A)):
        nextpos = i 
        while(nextpos>0 and A[nextpos] < A[nextpos-1]):
            A[nextpos], A[nextpos-1] = A[nextpos-1], A[nextpos]
            nextpos -= 1
    return A
    
for _ in range(int(input())):
    A = [int(x) for x in input().split()]
    print(*insertionSort(A))