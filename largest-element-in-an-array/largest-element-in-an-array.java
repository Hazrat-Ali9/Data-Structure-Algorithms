class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int x : nums){
            pq.add(x);
            if(pq.size() > k) pq.remove();
        }
        return pq.peek();
    }
}