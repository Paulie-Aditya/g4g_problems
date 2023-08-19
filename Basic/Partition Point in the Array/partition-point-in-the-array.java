//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

// Position this line where user code will be pasted.

// Driver class
class Array {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
            int n = Integer.parseInt(br.readLine());
            //            String line = br.readLine();
            //            String[] a2 = line.trim().split("\\s+");
            //            int n =Integer.parseInt(a2[0]);
            //            int m =Integer.parseInt(a2[1]);
            // int y =Integer.parseInt(a2[2]);
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(a1[i]);
            }
            Solution ob = new Solution();
            // ArrayList<Long> ans=ob.smallestDifferenceTriplet(a,b,c,n);
            long ans = ob.FindElement(a, n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    long FindElement(long arr[], int N) {
        long res = arr[0];
        long great = arr[0];
        long maxe = -1;
        for(int i = 1; i<N; i++){
            maxe = Math.max(maxe, arr[i-1]);
            if(great >= arr[i]){
                res = -1;
            }
            
            if(res == -1 && great < arr[i] && maxe < arr[i]){
                res = arr[i];
                great = arr[i];
            }
        }
        return res;
    }
}
