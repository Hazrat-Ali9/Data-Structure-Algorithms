class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return f(0, 0, s1, s2, s3, dp);
    }
    bool f(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        if(i+j == s3.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(i < s1.size() && s1[i] == s3[i+j]) ans |= f(i+1, j, s1, s2, s3, dp);
        if(j < s2.size() && s2[j] == s3[i+j]) ans |= f(i, j+1, s1, s2, s3, dp);
        return dp[i][j] = ans;
    }
};