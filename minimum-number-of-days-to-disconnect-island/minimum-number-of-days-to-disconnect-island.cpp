class Solution {
public:
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // Count initial islands
        int initialIslandCount = countIslands(grid);
        // Already disconnected or no land
        if (initialIslandCount != 1) {
            return 0;
        }
        // Try removing each land cell
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) continue;  // Skip water
                // Temporarily change to water
                grid[row][col] = 0;
                int newIslandCount = countIslands(grid);
                // Check if disconnected
                if (newIslandCount != 1) return 1;
                // Revert change
                grid[row][col] = 1;
            }
        }
        return 2;
    }
    int countIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islandCount = 0;
        // Iterate through all cells
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Found new island
                if (!visited[row][col] && grid[row][col] == 1) {
                    exploreIsland(grid, row, col, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
    // Helper method to explore all cells of an island
    void exploreIsland(vector<vector<int>>& grid, int row, int col,
                       vector<vector<bool>>& visited) {
        visited[row][col] = true;
        // Check all adjacent cells
        for (const auto& direction : dir) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            // Explore if valid land cell
            if (isValidLandCell(grid, newRow, newCol, visited)) {
                exploreIsland(grid, newRow, newCol, visited);
            }
        }
    }
    bool isValidLandCell(const vector<vector<int>>& grid, int row, int col,
                         const vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();
        // Check bounds, land, and not visited
        return row >= 0 && col >= 0 && row < rows && col < cols &&
               grid[row][col] == 1 && !visited[row][col];
    }
};