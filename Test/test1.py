def generate_primes(n):
    S = 1000
    primes = []
    nsqrt = int(pow(n, 0.5))
    is_prime = [True]*(nsqrt+1)
    for i in range(2, nsqrt+1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i*i, nsqrt+1, i):
                is_prime[j] = False

    result = 0
    cnt = 1
    for k in range(n//S):
        block = [True]*S
        start = k*S 
        for p in primes:
            start_idx = (start + p - 1)//p 
            j = max(start_idx, p)*p - start 
            while(j<S):
                block[j]=False
                j+=p 
        if k==0:
            block[0], block[1] = False, False 
        i = 0
        while(i < S and start + i<=n):
            if block[i]:
                result += 1
                if cnt == result:
                    print(i)
                    cnt += 100
            i += 1
    
generate_primes(10000)




