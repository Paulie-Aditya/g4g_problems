//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        vector<int> ans(26,0);
        
        for(int i = 0; i< str.size(); i++){
            ans[str[i]-'a']++;
        }
        
        int max = 0;
        
        for(int i = 0; i<26; i++){
            if(ans[i]>ans[max]){
                max = i;
            }
        }
        
        char temp = max+'a';
        return temp;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends