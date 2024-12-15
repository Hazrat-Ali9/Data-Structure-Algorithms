class Solution:
    def canCross(self, stones: List[int]) -> bool:
        dp = [[-1]*2001 for _ in range(2001)]
        mp = {}
        for i in range(0, len(stones)):
            mp[stones[i]] = i
        return self.f(dp, mp, stones, len(stones), 0, 0)
    def f(self, dp, mp, stones, n, i, prevJump):
        if i == n-1: return True
        if dp[i][prevJump] != -1: return dp[i][prevJump]
        ans = False
        for k in range(prevJump-1, prevJump+2):
            if k > 0 and stones[i]+k in mp:
                ans = ans or self.f(dp, mp, stones, n, mp[stones[i]+k], k)
        dp[i][prevJump] = ans
        return ans