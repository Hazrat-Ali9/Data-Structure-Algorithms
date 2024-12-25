class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9+7, arrLen;
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        this->arrLen = arrLen;
        dp = vector(arrLen, vector(steps+1, -1));
        return f(0, steps);
    }
    int f(int curr, int remain){
        if(remain == 0){
            if(curr == 0) return 1;
            return 0;
        }
        if(dp[curr][remain] != -1) return dp[curr][remain];
        int ans = f(curr, remain-1);
        if(curr > 0) ans = (ans + f(curr-1, remain-1)) % mod;
        if(curr < arrLen-1) ans = (ans + f(curr+1, remain-1)) % mod;
        dp[curr][remain] = ans;
        return ans;
    }
};