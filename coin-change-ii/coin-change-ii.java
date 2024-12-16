class Solution {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        int[][] dp = new int[n+1][amount+1];
        for(int i=0; i<n; i++){
            for(int j=0; j<=amount; j++){
                if(j == 0) dp[i][j] = 1;
                else{
                    int take = (coins[i]>j) ? 0 : dp[i][j-coins[i]];
                    int notTake = (i>0) ? dp[i-1][j] : 0;
                    dp[i][j] = take+notTake;
                }
            }
        }
        return dp[n-1][amount];
    }
}