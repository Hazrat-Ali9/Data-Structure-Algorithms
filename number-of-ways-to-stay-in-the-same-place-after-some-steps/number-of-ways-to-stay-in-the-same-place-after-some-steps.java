class Solution {
    int[][] dp;
    int mod = (int)1e9+7, arrLen;
    public int numWays(int steps, int arrLen) {
        arrLen = Math.min(steps, arrLen);
        this.arrLen = arrLen;
        dp = new int[arrLen][steps+1];
        for(int[] row : dp) Arrays.fill(row, -1);
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
}