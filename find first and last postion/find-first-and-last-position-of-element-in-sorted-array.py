class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l, r, f, s = 0, len(nums)-1, -1, -1
        while l <= r:
            m = (l+r)//2
            if nums[m]==target:
                f = m
                r = m-1
            elif nums[m] < target: l = m+1
            else: r = m-1
        l, r = 0, len(nums)-1
        while l <= r:
            m = (l+r)//2
            if nums[m]==target:
                s = m
                l = m+1
            elif nums[m] < target: l = m+1
            else: r = m-1
        return [f, s]