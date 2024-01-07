//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    struct Node* reverse(Node* head)
    {
        // Initialize current, previous and next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        struct Node* newRoot = new Node();
        struct Node* newCurr = newRoot;
        struct Node* curr1 = node1;
        struct Node* curr2 = node2;
        
        while(curr1 != NULL && curr2 != NULL ){
            if(curr1->data < curr2->data){
                newCurr->data = curr1->data;
                curr1 = curr1->next;
                
            }
            else{
                newCurr->data = curr2->data;
                curr2 = curr2->next;
            }
            newCurr->next = new Node();
            newCurr = newCurr->next;
        }
        while(curr1 != NULL ){
            newCurr->data = curr1->data;
            newCurr->next = new Node();
            newCurr = newCurr->next;
            curr1 = curr1->next;
        }
        while(curr2 != NULL ){
            newCurr->data = curr2->data;
            newCurr->next = new Node();
            newCurr = newCurr->next;
            curr2 = curr2->next;
        }
        
        newRoot = reverse(newRoot);
        return newRoot->next;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends