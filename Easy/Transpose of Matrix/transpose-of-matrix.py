#User function Template for python3
import math
class Solution:
    def transpose(self, matrix, n):
        # Write Your code here
        
        '''
        #mat[0][0] = mat[0][0]
        #mat[0][1] = mat[1][0]
        #mat[0][2] = mat[2][0]
        #mat[0][3] = mat[3][0]
        mat[1][0] = mat[0][1]
        #mat[1][1] = mat[1][1]
        mat[1][2] = mat[2][1]
        mat[1][3] = mat[3][1]
        mat[2][0] = mat[0][2]
        mat[2][1] = mat[1][2]
        mat[2][2] = mat[2][2]
        mat[2][3] = mat[3][2]
        mat[3][0] = mat[0][3]
        mat[3][1] = mat[1][3]
        mat[3][2] = mat[2][3]
        mat[3][3] = mat[3][3]
        '''
        
        for i in range(0,n):
            for j in range(i,n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]





#{ 
 # Driver Code Starts

#Initial Template for Python 3

for _ in range(int(input())):
    n = int(input())
    matrix = [
            list(map(int,input().split()))
            for _ in range(n)
        ]
        
    ob = Solution()
    ob.transpose(matrix, n)
    
    for row in matrix:
        print(*row)
    
# } Driver Code Ends