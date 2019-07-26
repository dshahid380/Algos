from math import gcd

def mult(a, b, mod):
	return a * b % mod

def f(x, c, mod):
	return (mult(x, x, mod) + c) % mod

def rho(n, x0=2, c=1):
	x = x0 
	y = x0 
	g = 1
	while(g==1):
		x = f(x, c, n)
		y = f(y, c, n)
		y = f(y, c, n)
		g = gcd(abs(x-y), n)
		
	return g
		

	 

n = 234
print(*rho(n))