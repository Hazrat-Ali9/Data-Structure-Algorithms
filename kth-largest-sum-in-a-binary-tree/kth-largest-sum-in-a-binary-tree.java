
class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            long sz = q.size(), sum = 0;
            for(int i=0; i<sz; i++){
                TreeNode node = q.remove();
                sum += node.val;
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
            }
            pq.add(sum);
        }
        if(pq.size() < k) return -1;
        for(int i=0; i<k-1; i++) pq.remove();
        return pq.peek();
    }
}
// Kth Largest sum in a binary tree