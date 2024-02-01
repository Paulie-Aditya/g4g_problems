//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        if(first == NULL){
            return second;
        }
        if(second == NULL){
            return first;
        }
        
        Node* curr1 = first;
        Node* prev1 = NULL;
        while(curr1 != NULL){
            Node* next = curr1->next;
            curr1->next = prev1;
            prev1 = curr1;
            curr1 = next;
        }
        
        Node* head1 = prev1;
        
        Node* curr2 = second;
        Node* prev2 = NULL;
        while(curr2 != NULL){
            Node* next = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = next;
        }
        Node* head2 = prev2;
        
        
        curr1 = head1;
        curr2 = head2;
        
        
        int carry = 0;
        Node* head = new Node(-1);
        Node* res = head;
        
        while(curr1!= NULL && curr2!= NULL){
            int val1 = curr1->data;
            int val2 = curr2->data;
            
            int sum = (val1+val2+ carry)%10 ;
            carry = (val1+val2+ carry)/10;
            
            res->next = new Node(sum);
            res = res->next;
            
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        while(curr1 != NULL){
            int val = curr1->data;
            int sum = (val+ carry)%10 ;
            carry = (val+carry)/10;
            
            res->next = new Node(sum);
            res = res->next;
            curr1 = curr1->next;
        }
        
        while(curr2!= NULL){
            int val = curr2->data;
            int sum = (val+ carry)%10 ;
            carry = (val+ carry)/10;
            
            res->next = new Node(sum);
            res = res->next;
            curr2 = curr2->next;
        }
        
        while(carry){
            res->next = new Node(carry%10);
            res = res->next;
            
            carry = carry/10;
        }
        
        head = head->next;
        Node* curr = head;
        Node* prev = NULL;
        while(curr!= NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        return prev;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends