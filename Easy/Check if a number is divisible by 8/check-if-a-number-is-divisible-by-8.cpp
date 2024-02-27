//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    
    int DivisibleByEight(string s){
        // last 3 digits
        
        int n = s.size();
        if(n<3){
            int ans = s[n-1]-'0';
            if(n == 2){
                ans += 10* (s[n-2]-'0');
            }
            
            if(ans%8 == 0){
                return 1;
            }
            else{
                return -1;
            }
        }
        
        int ans = 100* (s[n-3]-'0') + 10* (s[n-2]-'0') + 1* (s[n-1]-'0');
        
        if(ans%8 == 0){
            return 1;
        }
        else{
            return -1;
        }
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends