def edit_distance(s1, s2):
    m, n = len(s1), len(s2)
    dp = [[0]*(n+1) for i in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):
            if i == 0:
                dp[i][j] = j

            elif j==0:
                dp[i][j] = i

            elif s1[i-1]==s2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            
            else:

                dp[i][j] = min(dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+1)
    return dp[m][n]


for _ in range(int(input())):
    s1 = input()
    s2 = input()
    print(edit_distance(s1, s2))



