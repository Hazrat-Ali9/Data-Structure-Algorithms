class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return f(nums, dp, target);
    }
    int f(vector<int> &nums, vector<int>&dp, int target){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(int x : nums){
            if(x <= target) dp[target] += f(nums, dp, target-x);
        }
        return dp[target];
    }
};