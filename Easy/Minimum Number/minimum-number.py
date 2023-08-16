#User function Template for python3
import math
from math import gcd
class Solution:
    def minimumNumber(self, n, arr):
        #code here
        #find hcf of array
        """
        def gcd(x,y):
            
            highest = 1
            if x%y != 0:
                gcd(y,x%y)
            elif x%y == 0:
                return y
        """
            
        
        ans = arr[0]
        for i in range(n):
            ans=gcd(ans,arr[i])
        return (ans)





#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    for _ in range(int(input())):
        n=int(input())
        arr=[int(i) for i in input().split()]
        obj=Solution()
        print(obj.minimumNumber(n,arr))
# } Driver Code Ends