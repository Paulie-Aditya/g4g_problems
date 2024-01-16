//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x, int y, int n, vector<vector<int>>  visited, vector<vector<int>> m){
        if( (x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path){
        
        
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        //order: D L R U
        
        int newX;
        int newY;
        
        
        //down
        newX = x+1;
        newY = y;
        
        if(isSafe(newX, newY,n, visited, m)){
            path.push_back('D');
            solve(m, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        //left
        newX = x;
        newY = y-1;
        
        if(isSafe(newX, newY,n, visited, m)){
            path.push_back('L');
            solve(m, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        //right
        newX = x;
        newY = y+1;
        
        if(isSafe(newX, newY,n, visited, m)){
            path.push_back('R');
            solve(m, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        
        //up
        newX = x-1;
        newY = y;
        
        if(isSafe(newX, newY,n, visited, m)){
            path.push_back('U');
            solve(m, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        if(m[0][0] == 0){
            return ans;
        }
        vector<vector<int>>visited = m;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j< n; j++){
                visited[i][j] = 0;
            }
        }
        
        solve(m, n, ans, 0 , 0, visited, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends