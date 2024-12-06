class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, mn = 0, float('inf')
        for i in range(0, len(prices)):
            mn = min(mn, prices[i])
            ans = max(ans, prices[i]-mn)
        return ans