from collections import defaultdict
def trial_division(n):
    fact = defaultdict(int)
    cnt = 0
    while(n%2==0):
        fact[2] += 1
        n //= 2

    d = 3 
    while(d*d <= n):
        while(n % d == 0):
            fact[d] += 1
            n //= d 
        d += 2

    if n > 1:
        fact[n]=1

    return fact 

 

while(True):
    n = int(input())
    if n==0:
        break 
    else:
        fact = trial_division(n)
        l = sorted(fact.keys())
        for i in l:
            print(str(i)+"^"+str(fact[i]), end=" ")
    print()
