#User function Template for python3


class Solution():
    def modulo(self, s, m):
        k = int(s,2)
        r = k % m 
        return r
        
            





#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        s,m = input().split()
        m = int(m)
        print(Solution().modulo(s, m))

# } Driver Code Ends