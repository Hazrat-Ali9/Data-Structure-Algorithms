// Binary tree inorder traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *curr = root, *prev;
        while(curr){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr;
                TreeNode *temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return ans;
    }
};