//{ Driver Code Starts
//Initial Template for C++
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


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        if(size==1)return (new Node(pre[0]));
        if(size==0)return NULL;
        map<int,int>mp;
        for(int i =0;i<size;i++){
            mp[preMirror[i]]=i;
        }
        return helper(0 ,size-1 , 0 , size-1 , pre , preMirror, mp);
    }
    Node * helper(int i , int  j ,int im , int jm , int pre[], int prem[],map<int,int>&mp){
        if(i==j and im==jm)return (new Node(pre[i]) );
        Node * head = new Node(pre[i]);
        int leftsize = jm - mp[pre[i+1]] +1;
        head->left = helper(i+1,i+leftsize , mp[pre[i+1]] , jm , pre , prem , mp);
        head->right = helper(i+leftsize+1 , j , im+1 , mp[pre[i+1]]-1,pre,prem,mp);
        return head;
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends