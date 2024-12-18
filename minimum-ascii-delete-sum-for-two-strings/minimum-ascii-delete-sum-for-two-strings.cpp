class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return computeCost(s1, s2, 0, 0, dp);
    }
    int computeCost(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(i==s1.size() && j==s2.size()) return 0;
        if(i == s1.size()){
            int deleteCost = 0;
            for(int p=j; p<s2.size(); p++) deleteCost += s2[p];
            return deleteCost;
        }
        if(j == s2.size()){
            int deleteCost = 0;
            for(int p=i; p<s1.size(); p++) deleteCost += s1[p];
            return deleteCost;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MAX;
        if(s1[i] == s2[j]) ans = computeCost(s1, s2, i+1, j+1, dp);
        else{
            ans = min(ans, s1[i] + computeCost(s1, s2, i+1, j, dp));
            ans = min(ans, s2[j] + computeCost(s1, s2, i, j+ 1, dp));
        }
        return dp[i][j] = ans;
    }
};