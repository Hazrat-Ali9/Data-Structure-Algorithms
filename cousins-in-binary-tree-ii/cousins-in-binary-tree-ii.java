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
    public TreeNode replaceValueInTree(TreeNode root) {
        int prevLevelSum = root.val;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            int levelSize = q.size(), currSum = 0;
            for(int i=0; i<levelSize; i++){
                TreeNode node = q.poll();
                node.val = prevLevelSum - node.val;
                int siblingSum = (node.left != null ? node.left.val : 0) + (node.right!=null ? node.right.val : 0);

                if(node.left != null){
                    currSum += node.left.val;
                    node.left.val = siblingSum;
                    q.offer(node.left);
                }
                if(node.right!=null){
                    currSum += node.right.val;
                    node.right.val = siblingSum;
                    q.offer(node.right);
                }
            }
            prevLevelSum = currSum;
        }
        return root;
    }
}