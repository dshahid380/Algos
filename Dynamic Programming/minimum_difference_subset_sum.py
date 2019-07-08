def find_min_subset_sum(A):
	SUM = sum(A)
	dp = [[False]*(SUM+1) for i in range(len(A)+1)]

	for i in range(len(A)+1):
		dp[i][0] = True

	for i in range(1, len(A)+1):
		for j in range(SUM+1):
			dp[i][j] = dp[i-1][j]

			if A[i-1] <= j:
				dp[i][j] = dp[i][j] or dp[i-1][j-A[i-1]]

	for j in range(SUM//2, -1,-1):
		if dp[len(A)][j]:
			return max(SUM-j, j)

for _ in range(int(input())):
	A = [int(x) for x in input().split()]
	print(find_min_subset_sum(A))
