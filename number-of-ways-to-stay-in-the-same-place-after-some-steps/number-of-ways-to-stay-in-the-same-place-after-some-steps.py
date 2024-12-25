class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        arrLen = min(arrLen, steps)
        dp = [[-1]*(steps+1) for _ in range(arrLen)]
        def f(curr, remain):
            if remain == 0:
                if curr==0: return 1
                return 0
            if dp[curr][remain] != -1: return dp[curr][remain]
            ans = f(curr, remain-1)
            if curr>0: ans = (ans + f(curr-1, remain-1)) % 1000000007
            if curr<arrLen-1: ans = (ans + f(curr+1, remain-1)) % 1000000007
            dp[curr][remain] = ans
            return ans
        return f(0, steps)