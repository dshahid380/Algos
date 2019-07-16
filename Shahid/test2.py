def isprime(n):
	c = 0
	for i in range(2,int(pow(n,0.5))+1):
		if n%i==0:
			c += 1
			#print("i :",i)
	if c==0:
		return True
	else:
		return False

def main():
	n = int(input())
	for i in range(2,n+1):
		if isprime(i):
			print(i, end=" ")

if __name__ == '__main__':
	main()