//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(string s, vector<string> &ans, string curr, int i, int n){
	        // choose string or don't choose
	        if(i >= n){
	           // ans.insert(curr);
	           if(curr != "")
	                ans.push_back(curr);
	            return;
	        }
	        solve(s, ans, curr, i+1, n);
	        solve(s, ans, curr+ s[i], i+1, n);
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    int n = s.size();
		    solve(s,ans, "", 0, n);
		    
		  //  vector<string> res;
		  //  for(auto el: ans){
		  //      res.push_back(el);
		  //    //  cout << el << " ";
		  //  }
		  sort(ans.begin(), ans.end());
		  //  return res;
		  return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends