#User function Template for python3
class Solution:
	
	def findSum(self,arr, n):
		# code here
		return sum(set(arr))


#{ 
 # Driver Code Starts
#Initial Template for Python 3





if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findSum(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends