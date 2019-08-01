"""2D fenwick tree gives the same result as 1D, the difference is that
it performs the range operations in two point in the given array. Assume that
you want to perform operation in a part of rectangle in the given matric array, then
fenwick tree can a good data structure to use provided there is only point update."""
def update(x, y, val):
    i = x
    while(i < len(A)):
        j = y
        while(j < len(A[0])):
            tree[i][j] += val
            j = j | (j+1)
        i = i | (i+1) 

def sum_upto(x, y):
    res = 0 
    i = x 
    while(i >= 0):
        j = y
        while(j >= 0):
            res += tree[i][j]
            j = (j & (j+1)) - 1
        i = (i & (i+1)) - 1
    return res 

def query(x1, y1, x2, y2):
    ans = sum_upto(x2, y2) + sum_upto(x1-1, y1-1) - sum_upto(x2, y1-1) - sum_upto(x1-1, y2)
    return ans 

def build():
    for i in range(len(A)):
        for j in range(len(A[0])):
            update(i, j, A[i][j])


for _ in range(int(input())):
    N = int(input())
    A = [[0]*N for i in range(N)]
    tree = [[0]*N for i in range(N)]
    build()
    while(True):
        l = [str(x) for x in input().split()]
        if l[0]=="END":
            break
        elif l[0]=="SET":
            update(int(l[1]), int(l[2]), int(l[3]))
        else:
            print(query(int(l[1]), int(l[2]), int(l[3]), int(l[4])))





