"""
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be? 

Problem Link : https://leetcode.com/problems/unique-paths-ii/
"""
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        A = obstacleGrid 
        m, n = len(A[0]), len(A)
        if len(A)==1:
            if 1 in A[0]:
                return 0 
            else:
                return 1
        elif len(A[0])==1:
            for i in range(len(A)):
                if A[i][0]==1:
                    return 0
            return 1
        elif A[n-1][m-1]==1 or A[0][0]==1:
            return 0
        else:
            M = [[0]*m for i in range(n)]
            if A[n-1][m-1]==0:
                M[n-1][m-1]=1
            for i in range(m-2,-1,-1):
                if A[n-1][i]==0:
                    M[n-1][i]=M[n-1][i+1]
                    
            for i in range(n-2,-1,-1):
                if A[i][m-1]==0:
                    M[i][m-1]=M[i+1][m-1]
            
            for i in range(n-2,-1,-1):
                for j in range(m-2, -1, -1):
                    if A[i][j]==0:
                        M[i][j]=M[i][j+1]+M[i+1][j]
            return M[0][0]
            
