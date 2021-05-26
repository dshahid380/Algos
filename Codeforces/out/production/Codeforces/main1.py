s = input()
ans, h, l = 0, 0, 0
"""
for i in s:
    if i == "L":
        l += 1

for i in s:
    if i == "S":
        ans += (h * l)
    if i == "L":
        l -= 1
    if i == "H":
        h += 1
"""
print(ans)
