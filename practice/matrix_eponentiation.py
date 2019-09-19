"""
def multiply(a, b): 
    
    mul = [[0 for x in range(3)] 
              for y in range(3)]; 
    for i in range(3): 
        for j in range(3): 
            mul[i][j] = 0; 
            for k in range(3): 
                mul[i][j] += a[i][k] * b[k][j]; 
  
    for i in range(3): 
        for j in range(3): 
            a[i][j] = mul[i][j];  
    return a;

#F = [[2,1,1], [1,0,0], [0,0,2]];
def power(n,M):
    if n==1:
        return M 
    elif n%2==0:
        y = power(n//2,M)
        x = multiply(y,y)
        return x 
    else:
        y = power(n-1,M)
        x = multiply(y,M)
        return x 

def solve(n):
    M = [[2,-1,1], [1,0,0], [0,0,2]]
    if n==0:
        return 1
    if n==1:
        return 5 
    elif n==2:
        return 10 
    else:
        X = power(n-2,M)
        ans = X[0][0]*5 + X[0][1] + X[0][2]
        return ans

print(solve(4))
"""
# Python3 program to find value of f(n) 
# where f(n) is defined as 
# F(n) = F(n-1) + F(n-2) + F(n-3), n >= 3 
# Base Cases : 
# F(0) = 0, F(1) = 1, F(2) = 1 

# A utility function to multiply two 
# matrices a[][] and b[][]. Multiplication 
# result is stored back in b[][] 
def multiply(a, b): 
    
    # Creating an auxiliary matrix 
    # to store elements of the 
    # multiplication matrix 
    mul = [[0 for x in range(3)] 
            for y in range(3)]; 
    for i in range(3): 
        for j in range(3): 
            mul[i][j] = 0; 
            for k in range(3): 
                mul[i][j] += a[i][k] * b[k][j]; 

    # storing the multiplication 
    # result in a[][] 
    for i in range(3): 
        for j in range(3): 
            a[i][j] = mul[i][j]; # Updating our matrix 
    return a; 

# Function to compute F raise 
# to power n-2. 
def power(F, n): 

    M = [[2,-1,1], [1,0,0], [0,0,2]] 

    # Multiply it with initial values i.e 
    # with F(0) = 0, F(1) = 1, F(2) = 1 
    if (n == 1): 
        return F[0][0] + F[0][1]+F[0][2]; 

    power(F, int(n / 2)); 

    F = multiply(F, F); 

    if (n % 2 != 0): 
        F = multiply(F, M); 

    # Multiply it with initial values i.e 
    # with F(0) = 0, F(1) = 1, F(2) = 1 
    return F[0][0] + F[0][1]+F[0][2] ; 

# Return n'th term of a series defined 
# using below recurrence relation. 
# f(n) is defined as 
# f(n) = f(n-1) + f(n-2) + f(n-3), n>=3 
# Base Cases : 
# f(0) = 0, f(1) = 1, f(2) = 1 
def findNthTerm(n): 
    F = [[2,-1,1], [1,0,0], [0,0,2]]

    return power(F, n - 2); 

# Driver code 
n = 5; 

print("F(5) is", 
    findNthTerm(n)); 

# This code is contributed by mits 











