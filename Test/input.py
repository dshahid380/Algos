from random import randint

text=open("input.in","w+")
n=70                      # No of test cases T
text.write(str(n)+"\n")
for i in range(n):
    N=randint(1,1000000)
    K=randint(1,10)
    text.write(str(N+K)+" "+str(K)+"\n") # Input N, K
    for i in range(N+K):
        a=randint(1,10000)
        text.write(str(a)+" ")         # Input Array a
    text.write("\n")
text.close()
