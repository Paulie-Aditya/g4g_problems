#User function Template for python3

class Solution:
    def nodeLevel(self, V, adj, X):
        q = []
        vis = [False for _ in range(V)]
        q.append(0)
        vis[0] = True
        level = 0
        while len(q) > 0:
            size = len(q)
            for i in range(size):
                curr = q.pop(0)
                if curr == X: return level
                for nei in adj[curr]:
                    if vis[nei] == False:
                        q.append(nei)
                        vis[nei] = True
            level += 1
        return -1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V,E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a,b = map(int,input().strip().split())
            adj[a].append(b)
            adj[b].append(a)
        X=int(input())
        ob = Solution()
        
        print(ob.nodeLevel(V, adj, X))
# } Driver Code Ends