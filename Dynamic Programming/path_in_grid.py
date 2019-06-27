def path(grid):
    m, n = len(grid[0]), len(grid)
    SUM = [[0]*(m) for i in range(n)]
    SUM[n-1][m-1]=grid[n-1][m-1]
        
    for i in range(n-2,-1,-1):
        SUM[i][m-1] = SUM[i+1][m-1]+grid[i][m-1]
        
    for i in range(m-2, -1, -1):
        SUM[n-1][i] = SUM[n-1][i+1]+grid[n-1][i]
            
    for i in range(n-2, -1, -1):
        for j in range(m-2, -1, -1):
            SUM[i][j] = min(SUM[i+1][j], SUM[i][j+1]) + grid[i][j]
    return SUM


for _ in range(int(input())):
    grid = []
    n, m = map(int, input().split())
    for i in range(n):
        L = [int(x) for x in input().split()]
        grid.append(L)
        L = []
    print(path(grid))
