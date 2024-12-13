class Solution {
    public int integerBreak(int n) {
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);
        return f(n, dp);
    }
    int f(int n, int[] dp){
        if(n==0 || n==1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = Math.max(ans, Math.max(f(n-i, dp)*i, i*(n-i)));
        }
        return dp[n] = ans;
    }
}