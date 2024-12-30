class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> dp(n, -1);
        return f(n-1, colors, neededTime, dp, 'A', neededTime[n-1]);
    }
    int f(int i, string &colors, vector<int> &neededTime, vector<int> &dp, char prevChar, int prevTime){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        if(colors[i] == prevChar) return dp[i] = min(prevTime, neededTime[i]) + f(i-1, colors, neededTime, dp, colors[i], max(prevTime, neededTime[i]));
        else return dp[i] = f(i-1, colors, neededTime, dp, colors[i], neededTime[i]);
    }
};