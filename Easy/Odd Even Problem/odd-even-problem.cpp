//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int n=s.length();
        int x=0, y=0;
        unordered_map<char, int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto i:mp){
            if(int(i.first)%2==0 && (i.second)%2 ==0){
                x++;
            }else if(int(i.first)%2!=0 && (i.second)%2 !=0){
                y++;
            }
        }
        int res=x+y;
        
        if(res%2==0)
        return "EVEN";
        return "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends