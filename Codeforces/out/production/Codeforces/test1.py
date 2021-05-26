import sys
import copy 
from collections import defaultdict
ONLINE_JUDGE = 1
if ONLINE_JUDGE:
	sys.stdin = open('input.in','r')


###### Start your logic here ######
def stringmethod(para, special1, special2, list1, strfind):
    
    """
    Remove special chars which is in special1 from para
    and store it into word1
    """
    word1 = ""
    for w in para.split():
        res = ""
        for ch in w:
            if ch in special1:
                continue
            else:
                res += ch
        word1 += res + " "
    #print(word1)

    """
    Get the first 70 characters from the word1, reverse it 
    and store it into variable rword2.
    """
    rword2 = copy.deepcopy(word1[:70])
    rword2 = rword2[::-1]
    print(rword2)
    
    """ 
    Remove wide spaces and print with special2 chars
    """
    resOfRword2 = ""
    for w in rword2.split():
        for ch in w:
            resOfRword2 += ch + special2
    print(resOfRword2[:-1])

    """
    if List1 word exists in para.
    """
    flag = 0
    for w in list1:
        if w not in para.split():
            flag = 1
    if flag:
        print("Every string in ", list1, "were not present")
    else:
        print("Every string in ", list1, "were present")

    """ Split the word from the word1 and print first 20
    words as list. 
    """
    print(word1.split()[:20])

    """ Print less frequently used words"""
    freq = defaultdict(int)

    for w in word1.split():
        freq[w] += 1

    d = defaultdict(list)
    for k in freq:
        if freq[k] < 3:
            d[freq[k]].append(k)
    
    
    word3 = word1.split()
    ans = []
    for w in d[1]:
        idx = 0
        for i in range(len(word3)):
            if word3[i] == w:
                idx = i
        ans.append([idx, w])
    ans = sorted(ans, reverse = True)
    ans1 = []
    for w in ans:
        ans1.append(w[1])
    if len(ans1) >= 20:
        print(ans1[:20][::-1])
        return

    ans = []
    for w in d[2]:
        idx = 0;
        for i in range(len(word2)):
            if word3[i] == w:
                idx = i 
        ans.append([idx, w])
    ans = sorted(ans, reverse = True)
    for w in ans:
        ans1.append(w[1])
    print(ans1[:20][::-1])





    print(word1.rindex(strfind))
    # print(len(word1))
    # print(word1[371:])
    # print(word1)





if __name__ == '__main__':
    para = input()
    spch1 = input()
    spch2 = input()
    qw1_count = int(input().strip())
    qw1 = []

    for _ in range(qw1_count):
        qw1_item = input()
        qw1.append(qw1_item)

    strf = input()

    stringmethod(para, spch1, spch2, qw1, strf)
