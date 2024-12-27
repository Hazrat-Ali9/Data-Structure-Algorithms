class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        f, s = 0, 0
        for x in nums:
            if x>=f:
                s = f
                f = x
            elif x>s: s = x
        return (f-1)*(s-1)