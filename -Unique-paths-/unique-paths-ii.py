class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n, m = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] or obstacleGrid[n-1][m-1]: return 0
        dp = [[0] * m for _ in range(n)]
        dp[0][0] = 1
        for i in range(1, n):
            if obstacleGrid[i][0]: dp[i][0] = 0
            else : dp[i][0] = dp[i-1][0]
        for j in range(1, m):
            if obstacleGrid[0][j]: dp[0][j] = 0
            else: dp[0][j] = dp[0][j-1]
        for i in range(1, n):
            for j in range(1, m):
                if not obstacleGrid[i][j]:
                    dp[i][j] = dp[i-1][j]+dp[i][j-1]
        return dp[n-1][m-1]