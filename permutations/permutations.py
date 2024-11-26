class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.generatePermu([], ans, nums)
        return ans
    def generatePermu(self, curr, ans, nums):
        if len(curr) == len(nums):
            ans.append(curr[:])
            return
        for x in nums:
            if x not in curr:
                curr.append(x)
                self.generatePermu(curr, ans, nums)
                curr.pop()