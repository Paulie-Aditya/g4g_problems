//{ Driver Code Starts

import java.util.*;
import java.io.*;
class Node {
        int data;
        Node left, right;
 
        Node(int item) {
            data = item;
            left = right = null;
        }
    }
class BinarySearchTree {
    public static Node root;
    BinarySearchTree() { 
        root = null; 
    }
    void insert(int key) {
       root = insertRec(root, key);
    }
    Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.data)
            root.left = insertRec(root.left, key);
        else if (key > root.data)
            root.right = insertRec(root.right, key);
        return root;
    }
 
    public static void inorder()  {
       inorderRec(root);
    }
    public static void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data);
            inorderRec(root.right);
        }
    }
 
    // Driver Program to test above functions
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int n=sc.nextInt();
            int []a=new int[n];
            BinarySearchTree obj1=new BinarySearchTree();
            for(int i=0;i<n;i++)
            {
                int b=sc.nextInt();
                obj1.insert(b);
            }
            //inorder();
            Solution obj=new Solution();
            boolean k=obj.isDeadEnd(root);
            if(k==true)
            System.out.println("1");
            else
            System.out.println("0");
        }       
    }
}


// } Driver Code Ends


/*class Node {
        int data;
        Node left, right;
 
        Node(int item) {
            data = item;
            left = right = null;
        }
    }*/

//Function should return true if a deadEnd is found in the bst otherwise return false.
class Solution
{
    public static void traverse(Node root, ArrayList<Integer> res, ArrayList<Integer> to_check){
        if(root == null){
            return;
        }
        if(root.left == null && root.right == null){
            //res.add(root.data);
            to_check.add(root.data);
            return;
        }
        else if(root.left == null || root.right == null){
            res.add(root.data);
            if(root.left == null){
                traverse(root.right,res,to_check);
                return;
            }
            else{
                traverse(root.left,res,to_check);
                return;
            }
        }
        else if(root.left != null && root.right != null){
            res.add(root.data);
            traverse(root.left,res,to_check);
            traverse(root.right,res,to_check);
            return;
        }
    }
    public static boolean isDeadEnd(Node root)
    {
        //Add your code here.
        ArrayList<Integer> res = new ArrayList<>();
        ArrayList<Integer> to_check = new ArrayList<>();
        traverse(root,res,to_check);
        res.add(0);
        
        for(int i = 0; i<to_check.size(); i++){
            int temp = to_check.get(i);
            if((res.indexOf(temp-1) != -1) && (res.indexOf(temp+1) != -1))
                return true;
        }
        return false;
    }
}