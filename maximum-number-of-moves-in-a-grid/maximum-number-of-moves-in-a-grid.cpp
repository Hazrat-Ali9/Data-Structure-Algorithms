class Solution {
public:
    
    const int dirs[3] = {-1, 0, 1};
    int DFS(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size(), m = grid[0].size();
        
        if (dp[row][col] != -1) return dp[row][col];
        int maxMoves = 0;
        for (int dir : dirs) {
           
            int newRow = row + dir, newCol = col + 1;
            
            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m &&
                grid[row][col] < grid[newRow][newCol]) {
                maxMoves = max(maxMoves, 1 + DFS(newRow, newCol, grid, dp));
            }
        }
        return dp[row][col] = maxMoves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxMoves = 0;
        for (int i = 0; i < n; i++) {
            int movesRequired = DFS(i, 0, grid, dp);
            maxMoves = max(maxMoves, movesRequired);
        }
        return maxMoves;
    }
};