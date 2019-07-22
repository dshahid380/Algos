for _ in range(int(input())):
	N = int(input())
	position = []
	for _ in range(N):
		a, b = map(int, input().split())
		position.append([a,b])
	A, B = map(int, input().split())
	king_pos = [[A, B], [A-1, B],[A-1, B-1],
	            [A, B-1], [A+1, B], [A+1, B+1],
	            [A, B+1], [A-1, B+1], [A+1, B-1]]
	possiblity = ['NO']*9

	for pos in position:
		x, y = pos[0], pos[1]
		for i in range(9):
			d = pow(x-king_pos[i][0], 2) + pow(y-king_pos[i][1], 2)
			if d==5:
				possiblity[i]="YES"

	if "NO" in possiblity:
		print("NO")
	else:
		print("YES")

