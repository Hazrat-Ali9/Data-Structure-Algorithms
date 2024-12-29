class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(k + 1, vector<int>(n, -1));
        return dfs(0, k, events, dp);
    }
    int dfs(int curIndex, int count, vector<vector<int>>& events, vector<vector<int>>& dp) {
        if (count == 0 || curIndex == events.size()) {
            return 0;
        }
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }
        int nextIndex = bisectRight(events, events[curIndex][1]);
        dp[count][curIndex] = max(dfs(curIndex+1, count, events, dp), events[curIndex][2] + dfs(nextIndex, count-1, events, dp));
        return dp[count][curIndex];
    }
    int bisectRight(vector<vector<int>>& events, int target) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};