//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long int arr[] ,long long int n , 
    long long int left , long long int right ,long long int
    mid , long long int &count){
        long long int i = left ;
        long long int j = mid+1;
        vector<long long int>ans;
        while(i<=mid && j<=right){
            if(arr[i] <= arr[j]){
                ans.push_back(arr[i]);
                i++;
            }
            
            else
            {
                count += mid-i+1;
                ans.push_back(arr[j]);
                j++;
            }
            
        }
        
        while(i<=mid){
            ans.push_back(arr[i]);
            i++;
        }
        while(j<=right){
            ans.push_back(arr[j]);
            j++;
        }
        
        long long int k = left;
        for(long long int i =0;i<ans.size();i++){
            arr[k++] = ans[i];
        }
        
    }
   void mergesort( long long int  arr[],long long int  n,
   long long int left,long long int right,long long int  &count){
        if(left < right){
            int mid = (right+left)/2;
            mergesort(arr , n , left , mid , count);
            mergesort(arr , n , mid+1 , right , count);
            merge(arr , n , left , right , mid , count);
        } 
    }
 
    long long int inversionCount(long long arr[], long long N)
    {
    long long int  count =0;
        mergesort(arr,N,0,N-1,count);
        return count;
}
};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends