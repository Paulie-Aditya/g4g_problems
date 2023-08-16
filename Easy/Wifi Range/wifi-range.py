#User function Template for python3
#User function Template for python3
class Solution:
    def wifiRange(self, N, S, X): 
        prev_high  = -1
        for i in range(N):
            if S[i]=="1":
                temp_high = i+X #farthest right where wifi can reach
                temp_low = i-X #farthest left where wifi can reach
                temp_low = max(temp_low, 0)
                temp_high = min(temp_high, N-1)
                if prev_high+1>=temp_low:   
#previous farthest right point+1 should be more than equal to current lowest
                    prev_high = temp_high   #update high
                else:
                    return False
        if prev_high == N-1:
            return True
        return False






#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        N,X = map(int,input().strip().split())
        S = input()
        ob = Solution()
        ans = ob.wifiRange(N, S, X)
        if ans:
            print(1)
        else:
            print(0)

# } Driver Code Ends