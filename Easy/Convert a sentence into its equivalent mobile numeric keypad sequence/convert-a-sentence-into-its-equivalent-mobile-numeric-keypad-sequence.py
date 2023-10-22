#User function Template for python3

class Solution:

    def printSequence(self,S):
        # code here
        x = {'A':"2",'B':"22",'C':'222','D':'3','E':'33','F':'333','G':'4','H':'44','I':'444',
        'J':'5','K':'55','L':'555','M':'6','N':'66','O':'666','P':'7','Q':'77','R':'777',
        'S':'7777','T':'8','U':'88','V':'888','W':'9','X':'99','Y':'999','Z':'9999',' ':'0'
        }
        
        ans = ""
        for i in S:
            ans+= x[i]
        
        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):

        inputStr = input()

        solObj = Solution()

        print(solObj.printSequence(inputStr))
# } Driver Code Ends