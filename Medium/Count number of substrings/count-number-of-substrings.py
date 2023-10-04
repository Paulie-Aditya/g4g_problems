#User function Template for python3
def solve(s,k):
        count = 0
        ans = ''
        d = dict()
        start = 0
        for i in range(len(s)):
            ans+=s[i]
            if s[i] in d:
                d[s[i]]+=1
            else:
                d[s[i]] = 1
            while len(d)>k:
                d[s[start]]-=1
                if d[s[start]]==0:
                    del d[s[start]]
                start+=1
                ans = ans[1:]
            count+=(i-start+1)
        return count
class Solution:
    def substrCount (self,s, k):
        return solve(s, k)-solve(s, k-1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int (input ())
for tc in range (t):
    s = input ()
    k = int (input ())
    ob = Solution()
    print (ob.substrCount (s, k))
# } Driver Code Ends