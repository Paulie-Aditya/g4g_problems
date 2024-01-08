//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int n = txt.size();
            int m = pat.size();
            vector<int> res;
            int i = 0;
            
            while(i+m-1 < n){
                if(txt[i] == pat[0]){
                    bool flag = true;
                    for(int j = 0; j<m; j++){
                        if(txt[i+j] != pat[j]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        res.push_back(i+1);
                    }
                    i++;
                }
                else{
                    i++;
                }
            }
            
            if(res.size() == 0){
                res.push_back(-1);
                return res;
            }
            return res;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends