class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        big, sBig, small, sSmall = 0, 0, float('inf'), float('inf')
        for x in nums:
            if x > big:
                sBig = big
                big = x
            else: sBig = max(sBig, x)
            if x < small:
                sSmall = small
                small = x
            else: sSmall = min(sSmall, x)
        return big*sBig - small*sSmall