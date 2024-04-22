#User function Template for python3

class Solution:
    def minRow(self,N,M,A):
        #code here
        answer = {}
        for i in range(N):
            answer[i+1] = A[i].count(1)
        
        return (sorted(answer.items(), key = lambda x: x[1]))[0][0]





#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N,M=map(int,input().strip().split(" "))
        A=[]
        for i in range(N):
            B=list(map(int,input().strip().split(" ")))
            A.append(B)
        ob=Solution()
        print(ob.minRow(N,M,A))
# } Driver Code Ends