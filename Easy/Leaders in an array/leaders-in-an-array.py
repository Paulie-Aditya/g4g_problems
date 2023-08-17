
class Solution:
    #Back-end complete function Template for Python 3
    
    #Function to find the leaders in the array.

                
    def leaders(self, A, N):
        list1=[A[-1]]
        maximum=A[-1]
        for i in range(-2,-N-1,-1):
            if A[i]>=maximum:
                list1.append(A[i])
                maximum=A[i]
        return list1[::-1]
                
            
            
        
        





#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


    
def main():
    
    T=int(input())
    
    while(T>0):
        
        
        N=int(input())
        
        A=[int(x) for x in input().strip().split()]
        obj = Solution()
        
        A=obj.leaders(A,N)
        
        for i in A:
            print(i,end=" ")
        print()
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends