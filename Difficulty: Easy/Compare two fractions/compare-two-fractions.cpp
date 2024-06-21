//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        vector<double> allNumbers;
        int num = 0;
        int len = 0;
        for(int i=0; i<str.length(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                num *= 10;
                num += str[i]-'0';
            }
            else if(str[i] == '/'){
                allNumbers.push_back(num);
                num = 0;
            }
            else if(str[i] == ','){
                allNumbers.push_back(num);
                num = 0;
                allNumbers.push_back(len);
                len = -2;
            }
            
            len++;
        }
        allNumbers.push_back(num);
        allNumbers.push_back(len);
        
        double num1 = allNumbers[0]/allNumbers[1];
        double num2 = allNumbers[3]/allNumbers[4];
        
        if(num1 > num2){
            return str.substr(0, allNumbers[2]);
        }
        else if(num1 < num2){
            return str.substr(allNumbers[2]+2, allNumbers[5]);
        }
        else{
            return "equal";
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends