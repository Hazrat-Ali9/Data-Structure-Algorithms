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
    public String tree2str(TreeNode root) {
        if(root == null) return "";
        StringBuilder ans = new StringBuilder();
        ans.append(root.val);
        if(root.left!=null) ans.append("(").append(tree2str(root.left)).append(")");
        else if(root.right != null) ans.append("()");
        if(root.right!=null) ans.append("(").append(tree2str(root.right)).append(")");
        return ans.toString();
    }
}