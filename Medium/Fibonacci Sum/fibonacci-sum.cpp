//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int fibSum(long long int N){
        //code here
               int m=1e9+7;
        if(N==0)return 0;
        if(N==1)return 1;
        if(N==2)return 2;
        int pre=0;
        int post=1;
       long long int sum=1;
        int count=2;
        long long int ksum=2;
        while(count<N)
        {
            count++;
            pre=post;
            post=sum;
            sum=pre+post;
            sum=sum%m;
            ksum+=sum;
            ksum=ksum%m;
        }
        
        return ksum; 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends