def transitionPoint(arr, n):
    #Code here
    try:
        return arr.index(1)
    except:
        return -1





#{ 
 # Driver Code Starts
#driver code
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(transitionPoint(arr, n))

# } Driver Code Ends