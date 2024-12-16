
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

// Construct String