#User function Template for python3

from typing import List
import sys
class Solution:
    def numberOfEnclaves(self, grid: List[List[int]]) -> int:
        # code here

        N = len(grid)
        M = len(grid[0])
        sys.setrecursionlimit(10**8)

        def isValidIdx(i, j):
            return i >= 0 and i < N and j >= 0 and j < M

        DIRECTIONS = [
            (0, 1),
            (1, 0),
            (-1, 0),
            (0, -1),
        ]

        def dfs(i, j):
            grid[i][j] = 0
            for u, v in DIRECTIONS:
                if isValidIdx(i + u, j + v):
                    if grid[i + u][j + v] == 1:
                        dfs(i + u, j + v)

        for i in range(N):
            if grid[i][0] == 1:
                dfs(i, 0)
            if grid[i][M - 1] == 1:
                dfs(i, M - 1)
        for i in range(M):
            if grid[0][i] == 1:
                dfs(0, i)
            if grid[N - 1][i] == 1:
                dfs(N - 1, i)
        return sum(x.count(1) for x in grid)

#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == "__main__":
    for _ in range(int(input())):
        n, m = map(int,input().strip().split())
        grid = []
        for i in range(n):
            grid.append([int(i) for i in input().strip().split()])

        obj=Solution()
        print(obj.numberOfEnclaves(grid))
# } Driver Code Ends