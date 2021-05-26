def solve(N, X, K, S):
    parts = []
    for i in range(N):
        if (i+1) % X == 0:
            st = str(S[i-X+1: i+1])
            parts.append(sorted(list(st), reverse=True))
    idx = N - N%X
    st = str(S[idx: N])
    parts.append(sorted(list(st), reverse=True))

    count = 0
    while(true):

    return 1


if __name__ == '__main__':
    n = 11
    K = 9
    X = 3
    S = "12345678912"
    print(solve(n, X, K, S))










# def solve(N, P_i):
#     d = []
#     for x in P_i:
#         d.append(x)
#
#     for i in range(N):
#         ans = 0
#         for j in range(i):
#             if P_i[j] != 0 and P_i[i] % P_i[j] == 0:
#                 ans = max(ans, d[j])
#         d[i] += ans
#     print(d) # Do not copy this line
#     return max(d)
