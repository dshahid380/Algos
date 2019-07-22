def generate_primes(n):
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

for i in range(int(input())):
	n = int(input())
	p = generate_primes(n)
	print(len(p))

