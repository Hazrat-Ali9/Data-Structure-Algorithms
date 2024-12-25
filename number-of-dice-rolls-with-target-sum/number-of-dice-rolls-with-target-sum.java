class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        int[][] dp = new int[n+1][target+1];
        for(int[] row : dp) Arrays.fill(row, -1);
        return f(n, target, k, dp);
    }
    int mod = 1000000007;
    int f(int n, int target, int k, int[][] dp){
        if(n==0 && target==0) return 1;
        if(n==0 || target<0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int sum = 0;
        for(int i=1; i<=k; i++){
            sum = (sum + f(n-1, target-i, k, dp)) % mod;
        }
        return dp[n][target] = sum;
    }
}