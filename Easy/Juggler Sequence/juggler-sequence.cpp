//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        if (n == 1)
            return {1};
            
        vector<int> ans;
        int prev = n;
            
        for(int i = 0; prev != 1; i++)
        {
            if(i)
                prev = floor(pow(prev, (prev % 2) + 0.5));
            
            ans.push_back(prev);    
        }
        
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

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends