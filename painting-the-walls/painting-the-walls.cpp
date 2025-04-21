class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        dp = vector(n, vector(n+1, -1));
        return f(0, n, cost, time);
    }
    int f(int i, int remain, vector<int> &cost, vector<int> &time){
        if(remain <= 0) return 0;
        if(i == n) return 1e9;
        if(dp[i][remain] != -1) return dp[i][remain];
        int paint = cost[i] + f(i+1, remain-1-time[i], cost, time);
        int dontPaint = f(i+1, remain, cost, time);
        dp[i][remain] = min(paint, dontPaint);
        return dp[i][remain];
    }
};