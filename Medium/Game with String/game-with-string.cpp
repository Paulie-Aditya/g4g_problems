//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        vector<int> freq(26,0);
        
        for(int i = 0; i< s.size(); i++){
            int num = s[i]-'a';
            freq[num]++;
        }
        
        int maxi = 0;
        
        while(k>0){
            maxi = 0;
            for(int i = 0; i<26; i++){
                if(freq[i] > freq[maxi]){
                    maxi = i;
                }
            }
            if(freq[maxi] == 0)
                break;
            else{
                freq[maxi]--;
            }
            k--;
        }
        
        int ans = 0;
        for(int i = 0; i<26; i++){
            ans += freq[i]*freq[i];
        }
        return ans;
            
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends