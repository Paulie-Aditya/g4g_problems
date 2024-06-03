//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        
        long MOD = 1000000007;
       
       vector<long long int> dp(n+1);
       dp[2] = 1;
       vector<long long int> fib(n+1);
       fib[0] = 0;
       fib[1] = 1;
       fib[2] = 1;
       
       for(int i = 3;i<=n; i++){
           dp[i] = (2*dp[i-1] + fib[i-3])%MOD;
           fib[i] = (fib[i-1]+fib[i-2])%MOD;
       }
       
       long long int sum = 0;
       
       for(int i = 2; i<=n; i++){
        //   sum += dp[i];
        // cout<< dp[i]<< " ";
        sum+= dp[i];
       }
       
       return sum%MOD;
       
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends