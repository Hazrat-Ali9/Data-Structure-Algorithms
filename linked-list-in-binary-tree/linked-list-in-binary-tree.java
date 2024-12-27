/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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