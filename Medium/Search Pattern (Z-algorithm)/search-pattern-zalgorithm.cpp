//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int n = txt.size();
            int m = pat.size();
            int i = 0;
            
            vector<int>res;
            
            while(i+m-1<n){
                if(txt[i] == pat[0]){
                    bool flag = true;
                    for(int j = 0; j<m; j++){
                        if(pat[j] != txt[i+j]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        res.push_back(i+1);
                        i++;
                    }
                    else{
                        i++;
                    }
                }
                else{
                    i++;
                }
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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends