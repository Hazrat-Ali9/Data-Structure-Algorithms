class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        l, ans, curr = 0, 0, 0
        for r in range(0, len(nums)):
            target = nums[r]
            curr += target
            while ((r-l+1)*target-curr > k):
                curr -= nums[l]
                l += 1
            ans = max(ans, r-l+1)
        return ans