#User function Template for python3

class Solution:
    def indexes(self, v, x):
        # Your code goes here
        
        to_return = []
        n = len(v)
        
        try:
            to_return.append(v.index(x))
        except:
            to_return.append(-1)
            
        try:
            to_return.append( n - v[::-1].index(x) - 1)
        except:
            to_return.append(-1)
        
        return to_return
    





#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        k = int(input())
        obj = Solution()
        ans = obj.indexes(a, k)
        if ans[0]==-1 and ans[1]==-1:
            print(-1)
        else:
            print(ans[0], end=' ')
            print(ans[1])

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends