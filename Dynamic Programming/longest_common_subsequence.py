def longest_common_subsequence(P, Q, n, m):
	if arr[n][m] != -1:
		return arr[n][m]
	if n==0 or m==0:
		return 0
	elif P[n-1]==Q[m-1]:
		result = 1 + longest_common_subsequence(P, Q, n-1, m-1)
	elif P[n-1] != Q[m-1]:
		tmp1 = longest_common_subsequence(P, Q, n-1, m)
		tmp2 = longest_common_subsequence(P, Q, n, m-1)
		result = max(tmp1, tmp2)
	arr[n][m] = result
	return result 

P = "ANCD"
Q = "ABCD"
arr = [[-1]*(len(Q)+1) for i in range(len(P)+1)]
print(longest_common_subsequence(P, Q, len(P), len(Q))) 
