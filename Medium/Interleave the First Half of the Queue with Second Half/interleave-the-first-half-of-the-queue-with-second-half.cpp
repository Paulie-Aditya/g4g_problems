//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        stack<int> s;
        int n = q.size();
        
        for(int i = 0; i<n/2; i++){
            s.push(q.front());
            q.pop();
        }
        for(int i = 0; i<n/2; i++){
            int val = s.top();
            q.push(val);
            s.pop();
        }
        for(int i = 0; i<n/2; i++){
            int val = q.front();
            q.push(val);
            q.pop();
        }
        for(int i = 0; i<n/2; i++){
            s.push(q.front());
            q.pop();
        }
        
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            res.push_back(q.front());
            q.pop();
            s.pop();
        }
        // while(!s.empty()){
        //     q.push(s.top());
        //     q.push(q.front());
        //     s.pop();
        //     q.pop();
        // }
        
        // vector<int> res;
        // while(!q.empty()){
        //     res.push_back(q.front());
        //     q.pop();
        // }
        return res;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends