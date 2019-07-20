from collections import defaultdict
def solve(height):
	
	maxx, l, r = 0, 0, len(height)-1
	while(l<r):
		maxx = max(maxx, min(height[l], height[r])*(r-l))
		if height[l]<height[r]:
			l+=1
		else:
			r -= 1
	return maxx

for _ in range(int(input())):
	A = [int(x) for x in input().split()]
	print(solve(A)) 



