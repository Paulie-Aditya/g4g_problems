//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        set<int> res;
        vector<string> temp;
        
        for(int i = 0; i<M; i++){
            string curr = "";
            for(int j = 0; j< N; j++){
                if(matrix[i][j] == 0){
                    curr+= "A";
                }
                else{
                    curr += "B";
                }
            }
            temp.push_back(curr);
        }
        
        int n = temp.size();
        for(int i = 0; i<n-1; i++){
            string curr = temp[i];
            for(int j = i+1; j<n; j++){
                if(temp[j] == curr){
                    res.insert(j);
                }
            }
        }
        
        vector<int> result;
        
        for (auto it = res.begin(); it != res.end(); it++)
            result.push_back(*it);
        
        sort(result.begin(), result.end()); 
        
        return result;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends