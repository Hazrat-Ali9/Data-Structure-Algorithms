class Solution {
    int[][] dp = new int[301][11];
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        for(int[] x : dp) Arrays.fill(x, -1);
        if(n < d) return -1;
        return f(jobDifficulty, n, 0, d);
    }
    int f(int[] jobD, int n, int i, int d){
        if(d == 1){
            int mx = Integer.MIN_VALUE;
            for(int j=i; j<n; j++) mx = Math.max(mx, jobD[j]);
            return mx;
        }
        if(dp[i][d] != -1) return dp[i][d];
        int ans = Integer.MAX_VALUE, curr = Integer.MIN_VALUE;
        for(int j=i; j<=n-d; j++){
            curr = Math.max(curr, jobD[j]);
            ans = Math.min(ans, curr + f(jobD, n, j+1, d-1));
        }
        dp[i][d] = ans;
        return ans;
    }
}