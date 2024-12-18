/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
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