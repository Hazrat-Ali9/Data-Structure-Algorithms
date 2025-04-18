class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int x : nums) pq.add(x);
        long ans = 0;
        while(k-- > 0){
            int mxEle = pq.poll();
            ans += mxEle;
            pq.add((int)Math.ceil(mxEle/3.0));
        }
        return ans;
    }
}