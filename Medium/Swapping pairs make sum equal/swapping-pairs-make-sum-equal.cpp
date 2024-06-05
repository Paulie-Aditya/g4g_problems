//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // find overall sum of both
        // both must be of equal sum -> totalsum/2
        // difference must exist between two pairs else -1
        
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i<n; i++){
            sum1+= a[i];
        }
        for(int i = 0; i<m; i++){
            sum2+=b[i];
        }
        
        if((sum1+sum2 )%2 != 0) return -1;
        int sum = (sum1+ sum2)/2;
        
        int diff1 = sum-sum1;
        int diff2 = sum-sum2;
        
        // cout << diff1 << " " << diff2 << endl;
        sort(a, a+n);
        sort(b, b+m);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int diff = a[i]-b[j];
                if((diff == diff1 && diff == -1*diff2) || (diff == -1*diff1 && diff == diff2))
                    return 1;
                    
                if(diff > diff1 || diff > diff2)
                    break;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends