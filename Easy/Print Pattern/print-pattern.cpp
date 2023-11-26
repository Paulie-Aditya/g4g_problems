//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{  
public:

    void solve(vector<int>& nums, int n){
        int k = nums.size();
        if(n <= 0){
            nums.insert(nums.begin()+k/2,n);
            return;
        } 
        nums.insert(nums.begin() + k/2, n);
        nums.insert(nums.begin() + k/2, n);
        
        solve(nums, n-5);
    }
    vector<int> pattern(int n){
        // code here
        vector<int> nums;
        solve(nums, n);   
        return nums;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends