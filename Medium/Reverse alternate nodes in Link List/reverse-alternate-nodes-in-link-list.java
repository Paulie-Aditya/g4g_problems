//{ Driver Code Starts
import java.util.*;
import java.lang.*;

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class Rearr
{
    static Node head;
    
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t  =sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            Node temp = head;
            for(int i = 1; i < n; i++)
            {
                int a = sc.nextInt();
                temp.next = new Node(a);
                temp = temp.next;
            }
            
            Solution ob = new Solution();
            ob.rearrange(head);
            printLast(head);
            System.out.println();
        }
    }
    
    public static void printLast(Node node)
    {
        while(node != null)
        {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }
}
// } Driver Code Ends


/*node class of the linked list
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}*/
class Solution
{
    public static void rearrange(Node odd)
    {
        // make ll of only odd nodes by temp.next = temp.next.next
        // rev = even nodes inserted at beginning
        
        //temp.next = rev
        Node temp = odd;
        Node rev = null;
        
        if(temp == null || temp.next == null || temp.next.next == null){
            return;
        }
        while(temp.next!= null && temp.next.next != null){
            Node curr = temp;
            
            if(rev == null){
                rev = curr.next;
                temp.next = temp.next.next;
                rev.next = null;
            }
            else{
                curr = curr.next;
                Node temporary = temp.next.next;
                curr.next = rev;
                temp.next = temporary;
                rev = curr;
            }
            temp = temp.next;
            
        }
        if(temp == null){
            temp = odd;
            while(temp.next != null)
                temp = temp.next;
            temp.next = rev;
        }
        else if(temp.next == null)
            temp.next = rev;
        else
            temp.next.next = rev;
    }
}
