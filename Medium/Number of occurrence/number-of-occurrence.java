//{ Driver Code Starts
//Initial Template for Java



import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int x = Integer.parseInt(inputLine[1]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().count(arr, n, x);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java



class Solution {
    int isPresent(int[] arr, int n, int x){
        int low = 0;
        int high = n-1;
        while(low<high){
            int mid = (low + (int)Math.floor(high-low+1)/2);
            if(arr[mid] == x){
                return mid;
            }
            else if(arr[mid]>x){
                high = mid-1;
            }
            else if(arr[mid]<x){
                low = mid;
            }
        }
        
        if (arr[low] == x){
            return low;
        }
    
        return -1;
        
    }
    int count(int[] arr, int n, int x) {
        // code here
        int mid = isPresent(arr,n,x);
        if (mid == -1){
            return 0;
        }
        int count = 0;
        //left search
        int left = mid;
        while(left>=0 && arr[left] == x){
            count++;
            left--;
        }
        mid++;
        if (mid>=n){
            return count;
        }
        while(mid<n && arr[mid] == x){
            count++;
            mid++;
        }
        
        return count;
        
    }
}