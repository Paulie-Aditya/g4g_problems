//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       int sign1=1,sign2=1;  
    if(s1[0]=='-')
        { sign1=-1; }
    if(s2[0]=='-')
        { sign2=-1; }
    int sign= sign1*sign2;
    int n = s1.size();
    int m = s2.size();
    if (n == 0 || m == 0)     return "0";
    vector<int> arr(n + m, 0);
    for(int i=n-1;i>=0;i--){
        if(s1[i]=='-')
                  continue;
        for(int j=m-1;j>=0;j--){
            if(s2[j]=='-')
                  continue;
            int m=(s1[i]-'0')*(s2[j]-'0');
            int sum=arr[i+j+1]+m;
            arr[i+j]+=sum/10;
            arr[i+j+1]=sum%10;
        }
    }
    string ans="";
    for(int i=0;i<arr.size();i++){
        if(ans.length()!=0 ||arr[i]!=0){
            ans+=to_string(arr[i]);
        }
    }
    if(ans.length()==0){
        return("0");
    }
    if(sign<0){
        return("-"+ans);
    }
    return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends