//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		 vector<int> arr(26,0);
        queue<char> q;
        
        string ans = "";
        
        for(int i = 0; i<A.size(); i++){
            char ch = A[i];
            int num = ch-'a';
            arr[num]++;
            
            q.push(ch);
            
            while(!q.empty()){
                if(arr[q.front()-'a'] > 1){
                    q.pop();
                }
                else{
                    ans += q.front();
                    break;
                }
            }
            if(q.empty()){
                ans+= "#";
            }
            
            
        }
        return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends