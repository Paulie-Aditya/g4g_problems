#User function Template for python3

def rotate(arr):
        n = len(arr)
        for i in range(n):
            arr[i] = arr[i][::-1]
        
        for i in range(0,n):
            for j in range(i,n):
                arr[i][j], arr[j][i] = arr[j][i], arr[i][j]


#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
	t = int(input())
	for _ in range(t):
		N=int(input())
		arr=[int(x) for x in input().split()]
		matrix=[]

		for i in range(0,N*N,N):
			matrix.append(arr[i:i+N])

		rotate(matrix)
		for i in range(N): 
			for j in range(N): 
				print(matrix[i][j], end =' ') 
			print() 
        

# } Driver Code Ends