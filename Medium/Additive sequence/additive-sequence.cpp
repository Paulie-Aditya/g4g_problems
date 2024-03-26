//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool solve(string s,int index,string a)
    {
        if(index>=s.size())
        {
            return true;
        }
        string temp="";
        bool ans=false;
        for(int i=index; i<index+3 && i<s.size(); i++)
        {
            temp+=s[i];
            string k="";
            for(int j=i+1; j<i+4 && j<s.size(); j++)
            {
                k+=s[j];
                if(stoi(temp)+stoi(a)==stoi(k) && j==s.size()-1)
                {
                    return true;
                }
                else if(stoi(temp)+stoi(a)==stoi(k))
                {
                    ans|=solve(s,i+1,temp);
                }
            }
        }
        return ans;
    }
    bool isAdditiveSequence(string n)
    {
        string a=n.substr(0,1);
        string b=n.substr(0,2);
        string c=n.substr(0,3);
        if(n.size()>=7)return solve(n,1,a) | solve(n,2,b) | solve(n,3,c);
        if(n.size()>=5)return solve(n,1,a) | solve(n,2,b);
        return solve(n,1,a);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends