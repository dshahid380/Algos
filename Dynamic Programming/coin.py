def solve(x):
	if x<0:
		return 99999 
	elif x==0:
		return 0 
	elif ready[x]:
		return value[x]
	else:
		best = 99999
		for c in coins:
			best = min(best, solve(x-c)+1)
		value[x] = best 
		ready[x] = True 
		return best 

n = 10 
coins = [1,3,4]
value =[9999]*11 
ready = [False]*11
print(solve(n))

