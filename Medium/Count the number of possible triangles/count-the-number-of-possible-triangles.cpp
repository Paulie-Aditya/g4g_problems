//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        int cnt = 0;
        //sort array
        // take 2 indexes and find largest el that satisfies
        // cnt += ans-j
        sort(arr, arr + n);
        for(int i = 0; i< n-2; i++){
            int el1 = arr[i];
            for(int j = i+1; j<n-1; j++){
                int el2 = arr[j];
                int m = n-1;
                
                while(m>j){
                    if((el1 + el2) > arr[m]){
                        cnt+= m-j;
                        break;
                    }
                    else{
                        m--;
                    }
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends