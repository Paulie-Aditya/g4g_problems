//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        
        int lo = 0;
        int hi = n-1;
        int mid = 0;
        
        int count = 0;
        
        while(mid <=hi){
            switch(a[mid]){
                case 0:
                    count++;
                    swap(a[lo],a[mid]);
                    lo++;
                    mid++;
                    break;
                    
                case 1:
                    mid++;
                    break;
                
                case 2:
                    count++;
                    swap(a[mid],a[hi]);
                    hi--;
                    break;
                
            }
        }
        
       
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends