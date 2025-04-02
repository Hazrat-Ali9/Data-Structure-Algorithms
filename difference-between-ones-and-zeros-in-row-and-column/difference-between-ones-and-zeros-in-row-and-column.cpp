class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        onesRow, onesCol = [0]*n, [0]*m
        for i in range(n):
            for j in range(m):
                onesRow[i] += grid[i][j]
                onesCol[j] += grid[i][j]
        ans = [[0]*m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                ans[i][j] = 2*onesRow[i] + 2*onesCol[j] - (n + m)
        return ans