//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}


// } Driver Code Ends
class Solution {
  public:
  


    void convert(Node *head, TreeNode *&root) {
            
        Node* temp = head;
        
        vector<TreeNode*> arr;
        while(temp!= NULL){
            TreeNode* curr = new TreeNode(temp->data);
            arr.push_back(curr);
            temp = temp->next;
        }
        int n = arr.size();
        
        for(int i = 0; i<n; i++){
            TreeNode* left = NULL;
            TreeNode* right = NULL;
            if(2*i + 1 < n)
                left = arr[2*i+1];
            if(2*i +2 < n)
                right = arr[2*i + 2];
            
            
            arr[i]->left = left;
            arr[i]->right = right;
        }
        
        root = arr[0];
        
         
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        Node *prevhead = head;
        TreeNode *root = NULL;
        Solution obj;

        obj.convert(head, root);
        if (root == NULL) {
            cout << "-1\n";
        } else if (root == NULL && prevhead != NULL) {
            cout << "-1\n";
        } else {
            lvl(root);
            cout << endl;
        }
        // inorder(root);
        getchar();
    }
    return 0;
}

// } Driver Code Ends