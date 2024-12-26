class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dp = {}
        ans = 1
        for a in arr:
            beforeA = dp.get(a-difference, 0)
            dp[a] = beforeA + 1
            ans = max(ans, dp[a])
        return ans