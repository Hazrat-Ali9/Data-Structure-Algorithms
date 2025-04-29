class Solution:
    def minOperations(self, nums: List[int]) -> int:
        mp = Counter(nums)
        ans = 0
        for cnt in mp.values():
            if cnt ==1: return -1
            ans += ceil(cnt/3)
        return ans