//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
import java.lang.*; 
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            long n = sc.nextLong();
    		System.out.println (new Solution().colName (n));
        }
        
    }
}

// Contributed By: Pranay Bansal 

// } Driver Code Ends


//User function Template for Java

class Solution
{
        String colName (long n) {
        n = n-1;
        StringBuilder ans = new StringBuilder();
        
        while(n >= 1) {
            ans.append((char)((int)(n%26) + 'A'));
            n = (n/26)-1;
        }
        if(n == 0) ans.append((char)((int)(n%26) + 'A'));
        return ans.reverse().toString();
    }
}