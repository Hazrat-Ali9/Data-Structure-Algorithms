class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dp = [[-1] * (target+1) for _ in range(n+1)]
        return self.f(n, k, target, dp)
    mod = 1000000007
    def f(self, n, k, target, dp):
        if n==0 and target==0: return 1
        if n==0 or target<0: return 0
        if dp[n][target] != -1: return dp[n][target]
        s = 0
        for i in range(1, k+1):
            s = (s + self.f(n-1, k, target-i, dp)) % self.mod
        dp[n][target] = s
        return dp[n][target]