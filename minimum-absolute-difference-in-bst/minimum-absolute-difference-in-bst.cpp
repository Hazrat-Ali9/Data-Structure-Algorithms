
class Solution {
public:
    int ans = INT_MAX;
    TreeNode *preNode;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* node){
        if(node == NULL) return;
        dfs(node->left);
        if(preNode != NULL) ans = min(ans, node->val - preNode->val);
        preNode = node;
        dfs(node->right);
    }
};