//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int solve(int n, int maxi){
           if(n <= 6) return n;
           maxi = max(maxi, solve(n/2, n/2) + solve(n/3, n/3) + solve(n/4, n/4));  
           return maxi;
        }
        int maxSum(int n)
        {
          return solve(n, n);
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
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends