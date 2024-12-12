class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(0, i):
                if nums[i] > nums[j] and dp[i] <= dp[j]:
                    dp[i] = dp[j]+1
        return max(dp)