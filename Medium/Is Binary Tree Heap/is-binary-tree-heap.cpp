//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    void count(struct Node* root, int &countofNodes){
        if(root == NULL){
            return;
        }
        countofNodes++;
        count(root->left, countofNodes);
        count(root->right, countofNodes);
    }
    bool isCBT(struct Node* root, int idx, int countOfNodes){
        if(root == NULL){
            return true;
        }
        if(idx >= countOfNodes){
            return false;
        }
        
        bool left = isCBT(root->left, 2*idx + 1, countOfNodes);
        bool right = isCBT(root->right, 2*idx + 2, countOfNodes);
        
        return left&&right;
    }
    
    pair<int, bool> isMaxOrder(struct Node* root){
        if(root == NULL){
            return {-1, true};
        }
        if(root->left == NULL && root->right == NULL){
            return {root->data,true};
        }
        
        pair<int, bool> left = isMaxOrder(root->left);
        pair<int, bool> right = isMaxOrder(root->right);
        
        if(left.second && right.second && root->data > left.first && root->data > right.first){
            return {root->data, true};
        }
        else{
            return {root->data, false};
        }
        
    }
    bool isHeap(struct Node* tree) {
        // must be cbt
        // node value greater than children
        int countOfNodes = 0;
        count(tree, countOfNodes);
        return isCBT(tree, 0 , countOfNodes) && isMaxOrder(tree).second;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends