class A:
    def __init__(self, a,b):
        self.a = a
        self.b = b

l = []
l.append(A(1,2))
l.append(A(2,1))
l.append(A(0,3))
def compare(x,y):
    return x.b - y.b 

from functools import cmp_to_key
B = sorted(l, key=cmp_to_key(compare))
print(B[0].b, B[1].b,B[2].b)