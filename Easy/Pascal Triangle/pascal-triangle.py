#User function Template for python3

#User function Template for python3
class Solution:

    def nthRowOfPascalTriangle(self,n):

     ans = [1]*n

     for i in range(0,n-1):

             for j in range(i,0,-1):

                 ans[j] = (ans[j]+ans[j-1])%1000000007

     return ans





#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 

	tc=int(input())
	while tc > 0:
	    n=int(input())
	    ob = Solution()
	    ans=ob.nthRowOfPascalTriangle(n)
	    for x in ans:
	        print(x, end=" ")
	    print()
	    tc=tc-1
# } Driver Code Ends