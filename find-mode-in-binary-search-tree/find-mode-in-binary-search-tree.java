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
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> mp = new HashMap();
        Queue<TreeNode> q = new LinkedList();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode node = q.remove();
            mp.put(node.val, mp.getOrDefault(node.val, 0)+1);
            if(node.left!=null) q.add(node.left);
            if(node.right!=null) q.add(node.right);
        }
        int mxFreq = 0;
        for(int key : mp.keySet()) mxFreq = Math.max(mxFreq, mp.get(key));
        List<Integer> ans = new ArrayList();
        for(int key : mp.keySet()){
            if(mxFreq == mp.get(key)) ans.add(key);
        }
        int[] res = new int[ans.size()];
        for(int i=0; i<ans.size(); i++) res[i] = ans.get(i);
        return res;
    }
}