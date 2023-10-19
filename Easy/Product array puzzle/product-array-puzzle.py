#User function Template for python3

class Solution:
    def productExceptSelf(self, nums, n):
        #code here
        to_return = []
        prod = 1
        count = nums.count(0)
        if(count == 0):
            for i in nums:
                prod*=i
            for i in range(0, n):
                to_return.append(prod//nums[i])
        elif(count == 1):
            x = nums.index(0)
            to_return = [0]*n
            for i in range(0,x):
                prod*=nums[i]
            for i in range(x+1,n):
                prod*=nums[i]
            to_return[x] = prod
            
        else:
            to_return = [0]*n
        
        return to_return
        
                
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())

    for _ in range(t):
        n=int(input())
        arr=[int(x) for x in input().split()]

        ans=Solution().productExceptSelf(arr,n)
        print(*ans)
# } Driver Code Ends