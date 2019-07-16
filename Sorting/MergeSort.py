def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m 
    L, R = [], []

    # Spliting the array into two parts 
    for i in range(n1):
        L.append(arr[l+i])
    for j in range(n2):
        R.append(arr[m+j+1])
    
    i, j, k = 0, 0, l

    # Now merge this two arrays
    while(i < n1 and j < n2):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
            k += 1
        else:
            arr[k] = R[j]
            j += 1
            k += 1
    while(i < n1):
        arr[k] = L[i]
        i += 1
        k += 1
    while(j < n2):
        arr[k] = R[j]
        j += 1
        k += 1

def mergeSort(arr, l, r):
    if l < r:
        m = (l+r)//2
        mergeSort(arr, l, m)
        mergeSort(arr, m+1, r)
        merge(arr, l, m, r)

for _ in range(int(input())):
    A = [int(x) for x in input().split()]
    mergeSort(A, 0, len(A)-1)
    print(*A)

