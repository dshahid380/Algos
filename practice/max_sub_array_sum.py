def maxSubArraySum(a):  

    size = len(a)   
    max_so_far = - pow(2, 64) - 1
    max_ending_here = 0
       
    for i in range(0, size): 
        max_ending_here = max_ending_here + a[i] 
        if (max_so_far < max_ending_here): 
            max_so_far = max_ending_here 
            
        if max_ending_here < 0: 
            max_ending_here = 0 
        
    return max_so_far

for _ in range(int(input())):
	A = [int(x) for x in input().split()]
	print(maxSubArraySum(A)) 
