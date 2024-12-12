class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] && dp[i] <= dp[j]) dp[i] = dp[j] + 1;
            }
        }
        int ans = 0;
        for(int x : dp) ans = Math.max(ans, x);
        return ans;
    }
}