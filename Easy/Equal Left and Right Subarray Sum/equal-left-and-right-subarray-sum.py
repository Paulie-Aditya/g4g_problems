# User function Template for python3

class Solution:
    # Complete this function
    
    #Function to find equilibrium point in the array.
    def equalSum(self,A, N):
        # Your code here
        if N==1:
            return 1
        sum_= sum(A)
        l=0
        r=0
        if A[0]==sum_:
            return A[0]
            
        for i in range(1,N):
            l=l+A[i-1]
            r=sum_-A[i]-l
            
            if l==r:
                return i+1
            
            
        return -1






#{ 
 # Driver Code Starts
# Initial Template for Python 3

import math


def main():

    T = int(input())

    while(T > 0):

        N = int(input())

        A = [int(x) for x in input().strip().split()]
        ob=Solution()

        print(ob.equalSum(A, N))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends