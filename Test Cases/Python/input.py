from random import randint
for k in range(5): #  number of test files
    text=open("input"+str(k)+".in","w+") # input1.in
    T=10  # No of test cases T
    text.write(str(T)+"\n")
    for i in range(T):
        N=randint(1,100)
        text.write(str(N)+"\n") # Input N, K
    text.close()