from math import floor
 
def sieve(n):
    prime_bool = [True]*(n+1)
    i = 2
    while(i*i<=n):
        if prime_bool[i]:
            j = i*i 
            while(j<=n):
                prime_bool[j] = False
                j += i 
        i += 1 
 
    primes = []
    for i in range(2,1+n):
        if prime_bool[i]:
            primes.append(i)
    return primes
 
def simple_sieve(l,r):
    n = r
    prime_bool = [True]*(n+1)
    i = 2
    prime_bool[0], prime_bool[1] = False, False 
    while(i*i<=n):
        if prime_bool[i]:
            j = i*i 
            while(j<=n):
                prime_bool[j] = False
                j += i 
        i += 1 
    for i in range(l, r+1):
        if prime_bool[i]:
            print(i)
 
def segmented_sieve(low, high):
    limit = floor(pow(high, 0.5))+1
    prime = sieve(limit)
    n = high - low + 1
    mark = [True]*n
    for i in range(len(prime)):
        lowLim = floor(low/prime[i])*prime[i];
        if lowLim < low:
            lowLim += prime[i];
        for j in range(lowLim, high+1, prime[i]):
            mark[j-low] = False
    
    for i in range(low, high+1):
        if mark[i-low]:
            print(i)
    print()
 
for i in range(int(input())):
    l, r = map(int, input().split())
    if r<1000000:
        simple_sieve(l, r)
    else:
        segmented_sieve(l, r)
 