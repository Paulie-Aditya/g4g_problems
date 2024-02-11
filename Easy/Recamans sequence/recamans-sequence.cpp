//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        map<int,int> map;
        vector<int> dp(n);
        
        dp[0] = 0;
        int i = 1;
        while(i < n){
            int temp = dp[i-1] - i;
            if(temp > 0 && !map.count(temp)){
                dp[i] = temp;
            }
            else{
                temp = dp[i-1] + i;
                dp[i] = temp;
            }
            map[temp]++;
            i++;
        }
        return dp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends