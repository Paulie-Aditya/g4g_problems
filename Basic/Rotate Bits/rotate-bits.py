#User function Template for python3

class Solution:
    def rotate(self, N, D):
        # code here
        to_return = []
        
        D = D%16
        
        if(D == 0):
            return [N,N]
        
        x = bin(N).lstrip('0b')
        while(len(x)!=16):
            x= '0'+x
        y = x
        
        #left rotation
        y = y+y[:D]
        y = y[D:]
        to_return.append(int(y,2))
        
        y = x
        #right rotation
        N = 16
        y = y[N-D:]+y
        y = y[:N]
        
        to_return.append(int(y,2))
        
        return to_return
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, d = input().strip().split(" ")
        n, d = int(n), int(d)
        ob = Solution()
        ans = ob.rotate(n, d)
        print(ans[0])
        print(ans[1])
# } Driver Code Ends