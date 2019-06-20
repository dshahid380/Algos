def solve(s):
	d = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
	l = list(s)
	l = l[::-1]
	ans = d[l[0]] 
	if len(l)==1:
		return d[l[0]]
	else:
		for i in range(1, len(l)):
			if d[l[i]]>=d[l[i-1]]:
				ans += d[l[i]]
			else:
				ans -= d[l[i]]
			
		return ans

for _ in range(int(input())):
	s = input()
	print(solve(s))


