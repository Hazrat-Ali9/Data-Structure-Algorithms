
class Solution {
    int ans = Integer.MAX_VALUE;
    TreeNode preNode;
    public int getMinimumDifference(TreeNode root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode node){
        if(node == null) return;
        dfs(node.left);
        if(preNode != null) ans = Math.min(ans, node.val - preNode.val);
        preNode = node;
        dfs(node.right);
    }
}