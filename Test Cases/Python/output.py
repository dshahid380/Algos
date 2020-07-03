from collections import defaultdict, deque
from itertools import permutations
from sys import stdin,stdout
from bisect import bisect_left, bisect_right
from copy import deepcopy
from random import randint
import sys

int_input=lambda : int(stdin.readline())
string_input=lambda : stdin.readline()
multi_int_input =lambda : map(int, stdin.readline().split())
multi_input = lambda : stdin.readline().split()
list_input=lambda : list(map(int,stdin.readline().split()))
string_list_input=lambda: list(string_input())
MOD = pow(10,9)+7

test= 1
for i in range(test):
    sys.stdin = open('input'+str(i)+'.in','r')
    #text= open('output'+str(i)+'.in','w')

    #solution
    for _ in range(int(input())):
        n=list(input())
        a=[int(i) for i in n]
        ans=''
        for i in range(len(a)-1):
            ans+=str(a[i]^a[i+1])
        if(len(a)>2):
            ans+=str(a[0]^a[-1])
        if(len(a)==1):
            ans=a[0]
        #text.write(str(ans)+'\n')
        print(ans)
        #Use single qoute to store in stdout
    #thats all