import sys
def closest_pair(arr1, arr2, m, n, x):
	diff = sys.maxsize
	l, r = 0, n-1
	while(l < m and r >= 0):
		if abs(arr1[l] + arr2[r] - x) < diff:
			val1, val2 = l, r
			diff = abs(arr1[l] + arr2[r] - x)
		if arr1[l] + arr2[r] > x:
			r -= 1
		else:
			l += 1

	return (val1, val2)

for _ in range(int(input())):
	m, n, x = map(int, input().split())
	arr1 = [int(i) for i in input().split()]
	arr2 = [int(i) for i in input().split()]
	l, r = closest_pair(arr1, arr2, m, n, x)
	print(arr1[l]+arr2[r])


