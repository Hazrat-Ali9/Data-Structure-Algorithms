class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        ans, n = 0, len(nums)
        for i in range(0, n//2): ans = max(ans, nums[i]+nums[n-1-i])
        return ans