// linked list
class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        if(root==null) return false;
        boolean ans = dfs(root, head);
        ans |= isSubPath(head, root.left);
        ans |= isSubPath(head, root.right);
        return ans;
    }
    boolean dfs(TreeNode node, ListNode head){
        if(head == null) return true;
        if(node == null) return false;
        boolean ans = false;
        if(node.val == head.val){
            ans |= dfs(node.left, head.next);
            ans |= dfs(node.right, head.next);
        }
        return ans;
    }
}