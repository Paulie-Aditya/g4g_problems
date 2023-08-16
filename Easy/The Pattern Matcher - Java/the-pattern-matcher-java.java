//{ Driver Code Starts
//Initial Template for Java


import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    
	public static void main (String[] args)
	{
	     //Taking input using Scanner class
    	 Scanner sc = new Scanner(System.in);
    	 
    	 //taking count of total testcases
    	 int t = sc.nextInt();
    	 
    	 boolean flag = false;
    	 while(t-- > 0){
    	   
    	   //taking the String
    	   String s=sc.next();
    	   
    	   Geeks obj=new Geeks();
    	   
    	   //calling follPatt() method
    	   //of class Geeks and passing
    	   //String as parameter
    	   obj.follPatt(s);
    	   
    	 }
    }
}


// } Driver Code Ends
//User function Template for Java



class Geeks{
    
    static void follPatt(String s) {
        
        int countX = 0;
        int countY = 0;
        int result = 1;
        
        while(s.length() > 1) {
            if(s.charAt(0) == 'y') {
        	    result = 0;
        	    break;
            }
        
        	 int indexX = s.indexOf('x');
             int indexY = s.indexOf('y');
             
             String subX = (s.substring(indexX, indexY));
             
             for(int i = indexY; i < s.length(); i++) {
            	 if(s.charAt(i) == 'y')
            		 countY++;
            	 else
            		 break;
             }
             for(int i = indexX; i < s.length(); i++) {
            	 if(s.charAt(i) == 'x') {
            		 countX++;
            	 } else {
            		 break;
            	 }
             }
             String subY = (s.substring(indexY, countX+countY));
             int l1 = subX.length();
             int l2 = subY.length();
             if(l1 != l2) {
              	result = 0;
              	break;
              } 
             if((countX+countY) < s.length()) {
            	 s = s.substring(countX+countY);
             }
             else if((countX+countY) == s.length()) {
            	 break;
             } else {
            	 continue;
             }
             countY = 0;
             countX = 0;
        }
        
        if(s.length() <= 1)
        	result = 0;
        
        if(s.length() == 2 && s.charAt(0) == 'x' && s.charAt(1) == 'y') {
     		result = 1;
     	}
     	
     	
       
        System.out.println(result);
	}
}



//{ Driver Code Starts.

// } Driver Code Ends