class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1;
        int right = row * col;
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (canCross(row, col, cells, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    bool canCross(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        queue<vector<int>> q;
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) {
                q.push({0, i});
                grid[0][i] = -1;
            }
        }
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int r = cur[0], c = cur[1];
            if (r == row - 1) {
                return true;
            }
            for (vector<int>& dir : directions) {
                int newRow = r + dir[0];
                int newCol = c + dir[1];
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == 0) {
                    grid[newRow][newCol] = -1;
                    q.push({newRow, newCol});
                }
            }
        }
        return false;
    }
};