class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
    int f(int n, vector<int> &dp){
        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max(ans, max(f(n-i, dp)*i, i*(n-i)));
        }
        return dp[n] = ans;
    }
};