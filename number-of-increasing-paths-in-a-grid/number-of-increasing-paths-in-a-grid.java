class Solution {
    public 
    int mod = 1000000007;
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int countPaths(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] dp = new int[n][m];
        // Iterate over all cells grid[i][j] and sum over dfs(i, j).
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                ans = (ans + dfs(grid, i, j, dp)) % mod;
            }
        }
        return ans;
    }
    int dfs(int[][] grid, int i, int j, int[][] dp) {
        // If dp[i][j] is non-zero, it means we have got the value of dfs(i, j),
        // so just return dp[i][j].
        if (dp[i][j] != 0) return dp[i][j];
        // Otherwise, set answer = 1, the path made of grid[i][j] itself.
        int ans = 1;
        for(int[] d : directions) {
            int nI = i + d[0], nJ = j + d[1];
            if(0 <= nI && nI < grid.length && 0 <= nJ && nJ < grid[0].length && grid[nI][nJ] < grid[i][j]){
                ans += dfs(grid, nI, nJ, dp);
                ans %= mod;
            }
        }
        // Update dp[i][j], so that we don't recalculate its value later.
        dp[i][j] = ans;
        return ans;
    }
}
// number of incresing paths in grid java