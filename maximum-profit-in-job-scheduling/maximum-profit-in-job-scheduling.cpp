class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs;
        for(int i=0; i<n; i++) jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        vector<int> dp(n, -1);
        return f(0, n, startTime, jobs, dp);
    }
    int f(int i, int n, vector<int> &st, vector<vector<int>> &jobs, vector<int>&dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ind = lower_bound(st.begin(), st.end(), jobs[i][1]) - st.begin();
        int take = jobs[i][2] + f(ind, n, st, jobs, dp);
        int notTake = f(i+1, n, st, jobs, dp);
        dp[i] = max(take, notTake);
        return dp[i];
    }
};