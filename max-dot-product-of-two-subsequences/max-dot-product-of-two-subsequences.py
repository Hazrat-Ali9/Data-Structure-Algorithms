class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        firMax, firMin, secMax, secMin = max(nums1), min(nums1), max(nums2), min(nums2)
        if firMax<0 and secMin>0: return firMax*secMin
        if secMax<0 and firMin>0: return secMax*firMin
        dp = [[0] * len(nums2) for _ in range(len(nums1))]
        return self.f(0, 0, nums1, nums2, dp)
    def f(self, i, j, nums1, nums2, dp):
        if i==len(nums1) or j==len(nums2): return 0
        if dp[i][j] != 0: return dp[i][j]
        dp[i][j] = max(nums1[i]*nums2[j]+self.f(i+1, j+1, nums1, nums2, dp), self.f(i+1, j, nums1, nums2, dp), self.f(i, j+1, nums1, nums2, dp))
        return dp[i][j]