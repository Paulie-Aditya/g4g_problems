#User function Template for python3

from typing import List

class Solution:
    def makeBeautiful(self, arr: List[int]) -> List[int]:
        stack=[]
        for ele in arr:
            if len(stack)==0:
                stack.append(ele)
            else:
                if stack[-1]>=0 and ele>0:
                    stack.append(ele)
                elif (stack[-1]>=0 and ele<0) or (stack[-1]<0 and ele>=0):
                    stack.pop()
                else:
                    stack.append(ele)
        return stack
        
        





#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        arr = list(map(int,input().split()))
        
        obj = Solution()
        res = obj.makeBeautiful(arr)
        print(*res)
# } Driver Code Ends