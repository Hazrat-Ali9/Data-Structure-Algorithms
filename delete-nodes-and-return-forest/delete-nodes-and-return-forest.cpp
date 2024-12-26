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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        unordered_set<int> toDelSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                if(toDelSet.find(curr->left->val) != toDelSet.end()) curr->left = NULL;
            }
            if(curr->right){
                q.push(curr->right);
                if(toDelSet.find(curr->right->val) != toDelSet.end()) curr->right = NULL;
            }
            if(toDelSet.find(curr->val) != toDelSet.end()){
                if(curr->left) forest.push_back(curr->left);
                if(curr->right) forest.push_back(curr->right);
            }
        }
        if(toDelSet.find(root->val) == toDelSet.end()) forest.push_back(root);

        return forest;
    }
};