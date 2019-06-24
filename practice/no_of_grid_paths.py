"""A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).
The robot can only move either down or right at any point in 
time. The robot is trying to reach the bottom-right corner of 
the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there? 

Problem Link : https://leetcode.com/problems/unique-paths/
"""
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        M = [[1]*m for i in range(n)]
        if m==1:
            return 1
        elif n==1:
            return 1
        elif m==2 and n==2:
            return 2
        else:
            for i in range(n-2,-1,-1):
                for j in range(m-2, -1, -1):
                    M[i][j]=M[i][j+1]+M[i+1][j]
            return M[0][0]
        