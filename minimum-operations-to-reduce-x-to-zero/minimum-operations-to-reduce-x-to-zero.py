class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        totalSum = sum(nums)
        l, r, currSum, length = 0, 0, 0, -1
        while r < len(nums):
            currSum += nums[r]
            while l<=r and currSum>totalSum-x:
                currSum -= nums[l]
                l += 1
            if currSum == totalSum-x: length = max(length, r-l+1)
            r += 1
        return -1 if length==-1 else len(nums)-length