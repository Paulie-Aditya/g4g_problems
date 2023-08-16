class Solution:
    
    def minDist(self, arr, n, x, y):
        xind, yind, min1 = -1, -1, float("inf")

        for i in range(n):
            if arr[i]==x: xind=i
            elif arr[i]==y: yind=i
        
            if (xind!=-1 and yind!=-1): min1 = min(min1, abs(xind-yind))

        if min1==float("inf"): return -1
        return min1
        
        
        
    





#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        x,y = list(map(int, input().strip().split()))
        print(Solution().minDist(arr, n, x, y))



# } Driver Code Ends