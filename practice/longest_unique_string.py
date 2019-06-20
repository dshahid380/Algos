def longest_unique_string(s):
        l, P = [], []
        for i in s:
            if i not in l:
                l.append(i)
            else:
                P.append(len(l))
                l = []
                l.append(i)
        if len(s)==0:
            return 0
        elif len(P)==0:
            return len(s)
        print(max(max(P),len(l)))

s = input()
l, P = [], []
for i in s:
    if i not in l:
        l.append(i)
    else:
        P.append(len(l))
        idx = l.index(i)
        l = l[idx+1:]
        l.append(i)
    print(l)
if len(s)==0:
    print(0)
elif len(P)==0:
    print(len(s))
print(max(max(P),len(l)))