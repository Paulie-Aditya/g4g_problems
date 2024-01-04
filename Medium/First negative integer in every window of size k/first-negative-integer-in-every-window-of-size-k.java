//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
	        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            long a[] = new long[(int)(n)];
            // long getAnswer[] = new long[(int)(n)];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(inputLine[i]);
            }
            int k = Integer.parseInt(br.readLine().trim());
            
            Compute obj = new Compute();
            long answer[] = obj.printFirstNegativeInteger(a, n, k);
            int sz = answer.length;
            
            StringBuilder output = new StringBuilder();
            for(int i=0;i<sz;i++)
                output.append(answer[i]+" ");
            System.out.println(output);
            
        }
	}
}


// } Driver Code Ends


//User function Template for Java


class Compute {
    
    public long[] printFirstNegativeInteger(long arr[], int n, int k)
    {
        int start = 0;
        int end = k-1;
        ArrayList<Long> list = new ArrayList<>();
        
        while(end<n){
            boolean found = false;
            for(int i = start ; i<=end; i++){
                if(arr[i]<0){
                    list.add(arr[i]);
                    found = true;
                    break;
                }
            }
            
            if(!found){
                list.add(0L);
            }
            
            start++;
            end++;
        }
        
        long[] res = new long[list.size()];
        for(int i = 0; i< list.size(); i++){
            res[i] = list.get(i);
        }
        
        return res;
        
        
    }
}