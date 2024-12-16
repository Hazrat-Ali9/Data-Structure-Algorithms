class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
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
};