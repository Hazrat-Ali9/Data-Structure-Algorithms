
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        bool ans = dfs(root, head);
        ans |= isSubPath(head, root->left);
        ans |= isSubPath(head, root->right);
        return ans;
    }
    bool dfs(TreeNode *node, ListNode *head){
        if(!head) return true;
        if(!node) return false;
        bool ans = false;
        if(node->val == head->val){
            ans |= dfs(node->left, head->next);
            ans |= dfs(node->right, head->next);
        }
        return ans;
    }
};