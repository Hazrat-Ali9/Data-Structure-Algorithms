/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        reverse(v.begin(), v.end());
        replaceVal(root, v);
        return root;
    }
    void inOrder(TreeNode *root, vector<int> &v){
        if(root == NULL) return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    void replaceVal(TreeNode *root, vector<int> &v){
        if(root == NULL) return;
        replaceVal(root->left, v);
        replaceVal(root->right, v);
        int nodeSum = 0;
        for(auto x : v){
            if(x > root->val) nodeSum += x;
            else break;
        }
        root->val += nodeSum;
    }
};