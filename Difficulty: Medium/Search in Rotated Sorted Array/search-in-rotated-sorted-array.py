#User function Template for python3

class Solution:
    def search(self,arr,key):
        # Complete this function
        try:
            return (A.index(key))
        except:
            return -1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.search(A, k))

# } Driver Code Ends