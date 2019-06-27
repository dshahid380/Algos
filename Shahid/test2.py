def fib(limit, terms):
	l = [0, 1, 2]
	for i in range(3,terms+1):
		a = l[i-1]+l[i-2]
		if a > limit:
		    break
		else: 
			l.append(l[i-1]+l[i-2])
	return l

l = fib(4000000,1000)
s = 0
for i in range(2, len(l), 2):
	if l[i]%2==0:
		s+=l[i]

print(s)


