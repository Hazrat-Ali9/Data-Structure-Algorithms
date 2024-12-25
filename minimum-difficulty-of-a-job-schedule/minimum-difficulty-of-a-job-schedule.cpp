class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d: return -1
        dp = [[-1 for _ in range(d + 1)] for _ in range(n + 1)]
        return self.f(jobDifficulty, n, 0, d, dp)
    def f(self, jobD, n, i, d, dp):
        if d == 1:
            return max(jobD[i:])
        if dp[i][d] != -1: return dp[i][d]
        ans, curr = float('inf'), float('-inf')
        for j in range(i, n-d+1):
            curr = max(curr, jobD[j])
            ans = min(ans, curr+self.f(jobD, n, j+1, d-1, dp))
        dp[i][d] = ans
        return ans