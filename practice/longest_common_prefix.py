def common_prefix(s1, s2):
	s = ""
	for i in range(min(len(s1), len(s2))):
		if s1[i]==s2[i]:
			s += s1[i]
		else:
			break
	return s 

def longest_common_prefix(S):
	if len(S)==1:
		return S[0]
	elif len(S)==2:
		return common_prefix(S[0], S[1])
	else:
		S1 = common_prefix(S[0],S[1])
		for i in range(2, len(S)):
			S1 = common_prefix(S1, S[i])
		return S1 

for _ in range(int(input())):
	S = [x for x in input().split()]
	print(longest_common_prefix(S))
