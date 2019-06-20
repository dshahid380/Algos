"""
Finding median of two sorted arrays
"""
def median(A, n):
  if n==1:
    return float(A[0])
  else:
    if n % 2 == 0:
      return float(A[n//2] + A[n//2 - 1])/2 
    else:
      return float(A[n//2])

def get_median(A, B, m, n):
  if m == 1 and n == 1:
    return (A[0]+B[0])/2
  elif m==1 and n==2:
    x = sorted([A[0], B[0], B[1]])
    return x[1]
  elif m==2 and n==1:
    x = sorted([A[0], A[1], B[0]])
    return x[1]
  elif m==2 and n==2:
    x = sorted(A+B)
    return (x[1]+x[2])/2
  else:
    m1 = median(A,m)
    m2 = median(B,n)
    if m1==m2:
      return m1
    elif m1>m2:
      if n%2==0:
        return get_median(A[:m//2+1], B[n//2-1:], m//2+1, n//2+1)
      else:
        return get_median(A[:m//2+1], B[n//2:], m//2+1, n//2+1)
    else:
      if m%2==0:
        return get_median(A[m//2-1:], B[:n//2+1], m//2+1, n//2+1)
      else:
        return get_median(A[m//2:], B[:n//2+1], m//2+1, n//2+1)

for _ in range(int(input())):
  A = [int(x) for x in input().split()]
  B = [int(x) for x in input().split()]
  print(get_median(A, B, len(A), len(B)))




