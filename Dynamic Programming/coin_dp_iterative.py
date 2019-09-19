def solve(n):
	value = [9999]*(n+1)
	value[0]=0 
	for i in range(1,n+1):
		for c in coins:
			if i-c>=0 and value[i-c]+1<value[i]:
				value[i] = min(value[i], value[i-c]+1)
	return value[x]

coins = [1,3,4]
n = 10 
print(solve(10))