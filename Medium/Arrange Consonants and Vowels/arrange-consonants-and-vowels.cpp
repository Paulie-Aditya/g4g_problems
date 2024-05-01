//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        struct Node* head1 = new Node('a');
        struct Node* temp1 = head1;
        struct Node* head2 = new Node('b');
        struct Node* temp2 = head2;
        
        struct Node* temp = head;
        while(temp!= NULL){
            char ch = temp->data;
             struct Node* newNode = new Node(ch);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch== 'u'){
             temp1->next = newNode;
             temp1 = temp1->next;
            }
            else{
                temp2->next = newNode;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        
        
        if(head1->next == NULL || temp1 == head1) // no vowels
            return head2->next;
        
        head1 = head1->next;
        head2 = head2->next;
        
        temp1->next = head2;
        return head1;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends