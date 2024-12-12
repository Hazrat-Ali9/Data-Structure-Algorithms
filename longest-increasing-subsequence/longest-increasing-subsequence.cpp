class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0, prev = -1, n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(curr, prev, nums, dp);
    }
    int f(int curr, int prev, vector<int>&nums, vector<vector<int>>&dp){
        if(curr >= nums.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]) take = 1 + f(curr+1, curr, nums, dp);
        int notTake = 0 + f(curr+1, prev, nums, dp);
        dp[curr][prev+1] = max(take, notTake);
        return dp[curr][prev+1];
    }
};