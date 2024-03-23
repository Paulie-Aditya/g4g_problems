//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    unordered_map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        int mx=INT_MIN,mn=INT_MAX,maxcount=0;
        for(auto x:m){
            mn=min(mn,x.second);
            mx=max(mx,x.second);
        }
        for(auto x: m){
            if(x.second==mx)maxcount++;
        }
        if(mx==mn)
        return true;
        if(mn==mx-1 and maxcount==1){
        return true;
        }
        if(mn-1==0 and m.size()-1==maxcount)
        return true;
        return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends