// maximum level sum of binary tree

class Solution {
    public int maxLevelSum(TreeNode root) {
        int mxSum = Integer.MIN_VALUE, ans = 0, level = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            level++;
            int sum = 0;
            for(int i=q.size(); i>0; i--){
                TreeNode node = q.poll();
                sum += node.val;
                if(node.left != null) q.offer(node.left);
                if(node.right != null) q.offer(node.right);
            }
            if(mxSum < sum){
                mxSum = sum;
                ans = level;
            }
        }
        return ans;
    }
}