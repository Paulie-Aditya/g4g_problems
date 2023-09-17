#User function Template for python3

class Solution:
    #Function to return list containing first n fibonacci numbers.
    def printFibb(self,N):
        # your code here
        x = [1,1]
        
        if N == 1:
            x = [1]
            return x
            
        if N == 2:
            x == [1,1]
            return x
            
        
        for i in range(2,N):
            x.append(x[i-2]+x[i-1])
        return x
        





#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        
        n=int(input())
        res = Solution().printFibb(n)
        for i in range (len(res)):
            print (res[i], end = " ") 
        print()
# } Driver Code Ends