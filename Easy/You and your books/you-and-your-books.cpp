//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long ans = 0;
        int st = 0;
        
        
        while(st<n){
            long long curr = 0;
            if(arr[st] <=k){
                int temp = st;
                while(temp<n && arr[temp]<=k){
                    curr += arr[temp];
                    temp++;
                }
                ans = max(ans, curr);
                st = temp-1;
            }
            st++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends