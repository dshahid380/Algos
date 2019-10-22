from random import randint
for k in range(5): #  number of test files
    text=open("input"+str(k)+".in","w+") # input1.in
    T=70  # No of test cases T
    text.write(str(T)+"\n")
    for i in range(T):
        N=randint(1,10)
        text.write(str(N)+"\n") # Input N, K
        for i in range(N):
            x=randint(1,10)
            text.write(str(x)+" ")         # Input Array a
        text.write("\n")
    text.close()
