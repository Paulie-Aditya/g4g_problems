//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool isval(int i, int j, int n, int m) {
        if(i<n and i>=0 and j<m and j>=0) return 1;
        return 0;
    }
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
        int n=mat.size(),m=mat[0].size();
        int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]==0) {
                    for(int k=0;k<4;k++){
                        int nx=i+dx[k],ny=j+dy[k];
                        if(isval(nx,ny,n,m) and mat[nx][ny]==1) {
                            mat[nx][ny]=2;
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                mat[i][j]%=2;
            }
        }
       
        queue<vector<int>> qp;
        for(int i=0;i<n;i++) {
            if(mat[i][0]) {
                qp.push({i,0});
                mat[i][0]=0;
            }
        }
      
        int cur=1;
        while(qp.size()) {
            int sz=qp.size();
            while(sz--) {
                auto vec=qp.front();
                qp.pop();
                int x=vec[0],y=vec[1];
                if(y==m-1) return cur;
                for(int i=0;i<4;i++) {
                    int nx=x+dx[i],ny=y+dy[i];
                    if(isval(x+dx[i],y+dy[i],n,m) and mat[nx][ny]) {
                        mat[nx][ny]=0;
                        qp.push({nx,ny});
                    }
                }
            }
            cur++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends