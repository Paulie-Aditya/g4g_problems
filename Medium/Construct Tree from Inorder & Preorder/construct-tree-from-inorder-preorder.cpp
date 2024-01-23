//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n){
        
        if(index>=n || inOrderStart>inOrderEnd){
            return NULL;
        }
        
        int el = pre[index++];
        Node* root = new Node(el);
        int pos;
        for(int i =inOrderStart;i<=inOrderEnd; i++){
            if(in[i] == el){
                pos=i;
            }
        }
        
        root->left = solve(in, pre, index, inOrderStart,pos-1,n);
        root->right = solve(in,pre, index, pos+1, inOrderEnd, n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preorderIndex = 0;
        map<int,int> map;
        for(int i = 0; i<n; i++){
            map[in[i]] = i;
        }
        return solve(in,pre,preorderIndex,0,n-1,n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends