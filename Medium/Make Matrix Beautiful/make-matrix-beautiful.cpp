//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> mat, int n)
    {
        // code here
        int sum=0;
        int maxSum = 0;
        
        for (int i=0; i<n; i++) {
            int rsum=0;
            int csum=0;
            for (int j=0; j<n; j++) {
                sum += mat[i][j];
                rsum += mat[i][j];
                csum += mat[j][i];
            }
            maxSum = max({maxSum, csum, rsum});
        }
        
        maxSum *= n;
        return maxSum - sum;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends