def flood_fill(r, c, c1, c2):
    if r<0 or r>=R or c<0 or c>=C:
        return 0
    elif grid[r][c] != c1:
        return 0 
    ans = 1
    grid[r][c] = c2

    for i in range(8):
        ans += flood_fill(r+dr[d], c+dc[d], c1, c2)

dr = [1, 1, 0, -1, -1, 0, 1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]

C, R = map(int, input().split())
grid = []
for _ in range(R):
    L = list(input())
    grid.append(L)
print(flood_fill(R, C, 'W', '*'))