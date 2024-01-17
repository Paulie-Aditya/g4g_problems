//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void traverse(Node * root, vector<int> &traversal, bool leftOrRight){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        if(leftOrRight == true){
            //left
            traversal.push_back(root->data);
            if(root->left)
                traverse(root->left, traversal, true);
            else
                traverse(root->right, traversal, true);
        }
        else{
            if(root->right)
                traverse(root->right, traversal, false);
            else
                traverse(root->left, traversal, false);
            traversal.push_back(root->data);
        }
    }
    
    void leafNodes(Node * root, vector<int> &traversal){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root->right == NULL){
            traversal.push_back(root->data);
            return;
        }
        
        leafNodes(root->left, traversal);
        leafNodes(root->right, traversal);
        
    }
    vector<int> solve(Node *root){
        vector<int> res;
        //res.push_back(root->data);
        vector<int> leftTraversal;
        traverse(root->left , leftTraversal , true);
        
        int size = leftTraversal.size();
        for(int i = 0; i < size; i++){
            res.push_back(leftTraversal[i]);
        }
        
        // leaf nodes
        vector<int> leaves;
        leafNodes(root, leaves);
        for(auto i: leaves){
            res.push_back(i);
        }
        
        vector<int> rightTraversal;
        traverse(root->right , rightTraversal, false);
        size = rightTraversal.size();
        
        for(int i = 0; i< size; i++){
            res.push_back(rightTraversal[i]);
        }
        
        if(res.size() == 0){
            res.push_back(root->data);
        }
        else{
            res.insert(res.begin(), root->data); 
        }
        return res;
        
        
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        if(root-> left == NULL && root-> right == NULL){
            vector<int> ans;
            ans.push_back(root->data);
            return ans;
        }
        
        ans = solve(root);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends