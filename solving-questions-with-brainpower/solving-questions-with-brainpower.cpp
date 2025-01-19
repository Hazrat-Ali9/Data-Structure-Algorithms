#define ll long long
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<ll> dp(questions.size(), -1);
        return solve(0, questions, dp);
    }
    ll solve(int index, vector<vector<int>>&questions, vector<ll> &dp){
        if(index >= questions.size()) return 0;
        if(dp[index] != -1) return dp[index];
        ll takeIt = questions[index][0] + solve(index+questions[index][1]+1, questions, dp);
        ll leaveIt = solve(index+1, questions, dp);
        return dp[index] = max(takeIt, leaveIt);
    }
};
// Solving Question with Brain Power 