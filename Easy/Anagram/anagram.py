#User function Template for python3


class Solution:
    
    #Function is to check whether two strings are anagram of each other or not.
    def isAnagram(self,a,b):
        a_list=list(a)
        b_list=list(b)
        a_list.sort()
        b_list.sort()
        
        if a_list == b_list:
            return True
        else:
            return False
        
        #code here





#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        a,b=map(str,input().strip().split())
        if(Solution().isAnagram(a,b)):
            print("YES")
        else:
            print("NO") 
# } Driver Code Ends