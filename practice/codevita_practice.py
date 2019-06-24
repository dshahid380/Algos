from collections import defaultdict
def fill(x):
	if len(str(x))==1:
		return (str(0)+str(x))
	return str(x)
def Int(n):
	l = list(str(n))
	return [int(x) for x in l]

def List(s, d, n):
	l = []
	if n==12:
		for i in range(d, s-1, -1):
			if 1 not in Int(i) and 2 not in Int(i):
				l.append(i)
		return l 

	for i in range(d, s-1, -1):
		if n not in Int(i):
			l.append(i)
	return l 

def date_picker(comb, d):
	Date = defaultdict(list)
	for i in comb:
		if i in d:
			for j in d[i]:
				if j in comb:
					Date[i].append(j)
	return Date 


############################################
# Input
S = list(input())
L = []
for i in S:
	if i!=',':
		L.append(int(i))
############################################
comb = {}
for i in range(len(L)):
	for j in range(len(L)):
		comb[int(str(L[i])+str(L[j]))]=int(str(L[i])+str(L[j]))
Date = []
Time = []

# Month dictionary
d = {}
d[1]=List(1,31,1)
d[2]=List(1,28,2)
d[3]=List(1,31,3)
d[4]=List(1,30,4)
d[5]=List(1,31,5)
d[6]=List(1,30,6)
d[7]=List(1,31,7)
d[8]=List(1,31,8)
d[9]=List(1,30,9)
d[10]=List(1,31,1)
d[11]=List(1,30,1)
d[12]=List(1,31,12)

# Date Finding
Date = date_picker(comb, d)


comb1=[]
X = Int(Date[0])+Int(Date[1])
for i in comb:
	y = Int(i)
	if len(y)==1:
		if y[0] not in X:
			comb1.append(i)
	else:
		if y[0] not in X and y[1] not in X:
			comb1.append(i)








date = fill(Date[0])+str("/")+fill(Date[1])
time = fill(Time[0]) + str(":") + fill(Time[1])
print(date, time)






