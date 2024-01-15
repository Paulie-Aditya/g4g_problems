//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends

class Solution{
  public:
    void rearrangeArray(int arr[], int n) {
        // code here
       sort(arr,arr+n);
       int a[n];
       int k=0;
       int start = 0;
       int end = n - 1;
       int mid=(n-1)/2;
       while(start<=mid && end>=mid)
       {
            a[k++]=arr[start++];
            a[k++]=arr[end--];
       }
       for(int i=0;i<n;i++)
       {
           arr[i]=a[i];
       }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        obj.rearrangeArray(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends