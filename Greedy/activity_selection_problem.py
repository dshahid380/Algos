from collections import defaultdict

def sortFinal(arr):
	pairs = defaultdict(list)
	result = []
	for pair in arr:
		pairs[pair[1]].append(pair[0])
	for i in pairs:
		pairs[i] = sorted(pairs[i])

	l = sorted(list(pairs.keys()))
	for i in l:
		for j in pairs[i]:
			result.append([j, i])
	return result

def activitySelection(arr):
	sortedFinal = sortFinal(arr)
	i = 0 
	result = [0]
	for j in range(1,len(arr)):
		if sortedFinal[j][0] >= sortedFinal[i][1]:
			result.append(j)
			i = j
	return result

def main():
	s = [int(x) for x in input().split()]
	f = [int(x) for x in input().split()]
	arr = []
	for i in range(len(s)):
		arr.append([s[i],f[i]])
	ans = activitySelection(arr)
	print(*ans)

if __name__ == '__main__':
	main()