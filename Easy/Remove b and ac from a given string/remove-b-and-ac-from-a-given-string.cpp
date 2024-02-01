//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
  public:
    string stringFilter(string str) 
    { 
        //code here.
        string res = "";
        int n = str.size();
        for(int i = 0; i<n; i++){
            if(str[i] == 'a'){
                if(!((i+1)<n && str[i+1]=='c')){
                    res+='a';
                }
            }
            else if(str[i] == 'c'){
                if(!((i-1)>=0 && str[i-1]=='a')){
                    res+='c';
                }
            }
            else if(str[i] == 'b'){
                
            }
            else{
                res+=str[i];
            }
        }
        return res;
    } 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;
   		
   		Solution ob;
   		cout <<ob.stringFilter(s) << "\n";

   		
   	}

    return 0;
}
// } Driver Code Ends