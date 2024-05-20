//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int start = 0;
        int last  = n-1;
        int mid   = start + (last - start)/2;
        
     
       while (start <= last) {
        // Check if x is present at mid
        if (arr[mid] == k)
            return k;

        // If x greater, ignore left half
        if (arr[mid] <= k){
            
            start = mid + 1;
            
            
        }
        // If x is smaller, ignore right half
        else{
           
            last = mid - 1;
        
        }

            mid   = start + (last - start)/2;
      }
      
              if (abs(arr[start] - k) == abs(arr[last] - k))
          {
            return arr[start];
          }
          else if (abs(arr[start] - k) < abs(arr[last] - k))
          {
            return arr[start];
          }
          return arr[last];
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends