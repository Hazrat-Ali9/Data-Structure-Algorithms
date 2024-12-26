class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid[0].size();
        for(auto row : grid){
            int index = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin();
            cnt += (n - index);
        }
        return cnt;
    }
};