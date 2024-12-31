class Solution {
    public int[] getAverages(int[] nums, int k) {
        if(k == 0) return nums;
        int n = nums.length;
        int[] avg = new int[n];
        Arrays.fill(avg, -1);
        if(2*k+1 > n) return avg;
        long[] prefSum = new long[n+1];
        for(int i=0; i<n; i++) prefSum[i+1] = nums[i] + prefSum[i];
        for(int i=k; i<(n-k); i++){
            long sum = prefSum[i+k+1] - prefSum[i-k];
            int average = (int)(sum/(2*k+1));
            avg[i] = average;
        }
        return avg;
    }
}