//{ Driver Code Starts
import java.util.*;


class Solution
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			Queue g = new Queue();
			
			int q = sc.nextInt();
			while(q>0)
			{
				int QueryType = sc.nextInt();
				if(QueryType == 1)
				{
					int a = sc.nextInt();
					g.enqueue(a);
				}
				else if(QueryType == 2)
				System.out.print(g.dequeue()+" ");
			q--;
			}	
			System.out.println();
				
			
			
		t--;
		}
	}
}


// } Driver Code Ends


class Queue
{
    Stack<Integer> s1 = new Stack<Integer>(); 
    Stack<Integer> s2 = new Stack<Integer>(); 
    
    /*The method pop which return the element poped out of the stack*/
    int dequeue()
    {
	    // Your code here
	    while(!s1.isEmpty()) {
            s2.push(s1.pop());
        }
        
        int ans = -1;
        if(s2.isEmpty()){
            ans = -1;
        }
        else{
            ans = s2.pop();
        }
        
        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }
        return ans;
    }
	
    /* The method push to push element into the stack */
    void enqueue(int x)
    {
	    // Your code here	
	    s1.push(x);
	    
    }
}

