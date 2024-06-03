//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        int n = s.size();
        string res = "";
        
        bool allOnes = true;
        for(int i = 0; i<n; i++){
            if(s[i] == '0'){
                allOnes = false;
                break;
            }
        }
        
        if(allOnes){
            res+="1";
            for(int i= 0; i<n; i++)
                res+="0";
            return res;
        }
        
        bool added = false;
        for(int i = n-1; i>=0; i--){
            if(added){
                res = s[i]+res;
            }
            else{
                if(s[i] == '1'){
                    res = "0"+res;
                }
                else if(s[i] == '0'){
                    res= "1"+res;
                    added = true;
                }
            }
        }
        
        // remove leading zeroes
        int st = 0;
        while(st<n && res[st] == '0'){
            st++;
        }
        res = res.substr(st);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends