class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        cnt0, longestWin, start = 0, 0, 0
        for i in range(0, len(nums)):
            if nums[i] == 0: cnt0 += 1
            while cnt0 > 1:
                if nums[start] == 0: cnt0 -= 1
                start += 1
            longestWin = max(longestWin, i-start)
        return longestWin