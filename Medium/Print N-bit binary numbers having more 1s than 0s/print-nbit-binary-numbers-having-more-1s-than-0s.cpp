//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool check(string &s){
    int n=s.length();
    int count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') count1++;
        else if(s[i]=='0') count2++;
        if(count2>count1) return false;
    }
    return true;
    }
    set<string>st;
    void help(int n,string s){
        if(n==0){
            if(check(s)){
                st.insert(s);
            }
            return ;
        }
        help(n-1,s+'0');
        help(n-1,s+'1');
    }
    vector<string> NBitBinary(int n)
    {
        // Your code goes here
        st.clear();
        help(n,"");
        vector<string>ans;
        for(auto &x:st) ans.push_back(x);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends