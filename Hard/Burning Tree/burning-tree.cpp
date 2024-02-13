//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* parenting(Node* root, map<Node*, Node*> &nodeToParent){
        if(root == NULL){
            return NULL;
        }
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        
        Node* left = parenting(root->left, nodeToParent);
        Node* right = parenting(root->right, nodeToParent);
        
        if(left!=NULL){
            nodeToParent[left]=root;
        }
        if(right!=NULL){
            nodeToParent[right]=root;
        }
        
        return root;
    }
    
    void findingNode(Node* root, Node* &found, int target){
        if(root == NULL){
            return;
        }
        if(root->data == target){
            found = root;
            return;
        }
        findingNode(root->left, found, target);
        findingNode(root->right, found, target);
        
    }
    
    void solve(Node* found, map<Node*, bool> &visited, int &minTime, queue<Node*> &q, map<Node*, Node*> &nodeToParent){
        
        while(!q.empty()){
            
            int size = q.size();
            bool added = false;
            for(int i = 0; i< size; i++){
                Node* temp = q.front();
                q.pop();
                visited[temp]=1;
                if(temp->left != NULL && visited[temp->left] != true){
                    q.push(temp->left);
                    added = true;
                }
                if(temp->right != NULL && visited[temp->right] != true){
                    q.push(temp->right);
                    added = true;
                }
                if(nodeToParent[temp] != NULL && visited[nodeToParent[temp]] != true){
                    q.push(nodeToParent[temp]);
                    added = true;
                }
            }
            if(added)
                minTime++;
        }
    }
    int minTime(Node* root, int target) 
    {
        // creating map
        map<Node*, Node*> nodeToParent;
        nodeToParent[parenting(root, nodeToParent)] = NULL;
        Node* found = NULL;
        findingNode(root, found, target);
        
        map<Node*, bool> visited;
        int minTime = 0;
        queue<Node*> q;
        
        q.push(found);
        
        solve(found, visited, minTime, q, nodeToParent);
        return minTime;
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends