def roadDistance(N, heights, H):
    width = 0
    for i in range(N):
        if heights[i] > H:
            width += 2
        else:
            width += 1
    return width

N = int(input())
heights = []
for i in range(N):
    x = int(input())
    heights.append(x)
H = int(input())
out_ = roadDistance(N, heights, H)
print(out_)
