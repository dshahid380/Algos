from math import ceil 
MOD = 10**9 + 7
def MODexp(a,b):
	ans = 1
	a = a % MOD 
	while(b>0):
		if b&1:
			ans = (ans*a)%MOD 
		a = (a*a)%MOD 
		b>>=1 
	return ans
   

def mod(a,b):   
	ans = 0
	a = a % MOD 
	while(b>0):
		if b&1:
			ans = (ans+a)%MOD 
		a = (a<<1)%MOD 
		b>>=1 
	return ans
for _ in range(int(input())):
	N, K = map(int, input().split())
	l = K
	r = K + N - 1
	if N == 2:
		S = mod(K, K-1) 
		S%=MOD 
		S = mod(S, MODexp(2,MOD-2))
		print(S)
	else:
		a = K - 1
		d = N - 1
		n = a//d + 1
		Tn = a - (n-1)*d 
		#print("a:",a,"d:",d,"Tn:",Tn)
		ans = mod(n, Tn+a)
		ans%=MOD 
		ans = mod(ans, MODexp(2, MOD-2))

		print(ans)

