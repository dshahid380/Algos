from math import ceil

def egyptian(p, q):
	"""The arguments p and q are considered to be in
	p/q form and we have to print the all possible fractions.
	"""
	denominator = []
	while(p!=0):
		x = ceil(q/p)
		denominator.append(x)
		p = p*x - q
		q = x*q
	return denominator

def main():
	p, q = map(int, input().split())
	denominator = egyptian(p, q)
	for i in denominator:
		print("1/"+str(i))

if __name__ == '__main__':
	main()