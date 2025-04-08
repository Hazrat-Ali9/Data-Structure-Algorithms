class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int[][] vp = new int[nums1.length][2];
        for(int i=0; i<nums1.length; i++){
            vp[i] = new int[]{nums1[i], nums2[i]};
        }
        Arrays.sort(vp, (a, b) -> b[1] - a[1]);
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sum = 0;
        for(int i=0; i<k; i++){
            sum += vp[i][0];
            pq.add(vp[i][0]);
        }
        long ans = sum * vp[k-1][1];
        for(int i=k; i<nums1.length; i++){
            sum += vp[i][0] - pq.poll();
            pq.add(vp[i][0]);
            ans = Math.max(ans, sum*vp[i][1]);
        }
        return ans;
    }
}