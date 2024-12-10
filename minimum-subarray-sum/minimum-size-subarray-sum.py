class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, sumOfWin, ans = 0, 0, float('inf')
        for r in range(0, len(nums)):
            sumOfWin += nums[r]
            while sumOfWin >= target:
                ans = min(ans, r-l+1)
                sumOfWin -= nums[l]
                l += 1
        return ans if ans != float('inf') else 0