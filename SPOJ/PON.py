def check_composite(n, a, d, s):
	x = pow(a, d, n)
	if x==1 or x==n-1:
		return False
	for r in range(1, s):
		x = x * x % n
		if x==n-1:
			return False
	return True
 
def miller_rabin(n):
	if n<2:
		return False
	r = 0 
	d = n-1
	while((d&1)==0):
		d >>=1
		r += 1
	base = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
	for a in base:
		if n==a:
			return True
		if check_composite(n, a, d, r):
			return False
	return True
 
for _ in range(int(input())):
	n = int(input())
	if miller_rabin(n):
		print("YES")
	else:
		print("NO") 