
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int mxSum = INT_MIN, ans = 0, level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int sum = 0;
            for(int i=q.size(); i>0; i--){
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            if(mxSum < sum){
                mxSum = sum;
                ans = level;
            }
        }
        return ans;
    }
};