class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target+1];
        Arrays.fill(dp, -1);
        return f(nums, dp, target);
    }
    int f(int[] nums, int[] dp, int target){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(int x : nums){
            if(x <= target) dp[target] += f(nums, dp, target-x);
        }
        return dp[target];
    }
}