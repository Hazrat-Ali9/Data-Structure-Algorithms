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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        sideView(root, 0, ans);
        return ans;
    }
    void sideView(TreeNode* root, int level, vector<int> &ans){
        if(root==NULL) return;
        if(ans.size() == level) ans.push_back(root->val);
        sideView(root->right, level+1, ans);
        sideView(root->left, level+1, ans);
    }
};