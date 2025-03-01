class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> dp(1<<17, 0);
        dp[0] = 1;
        int mx = 0;
        for(int x : nums){
            for(int i=mx; i>=0; i--) dp[i | x] += dp[i];
            mx |= x;
        }
        return dp[mx];
    }
};