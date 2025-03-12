class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        dp = {-1 : True}
        def f(i):
            if i in dp: return dp[i]
            ans = False
            if i>0 and nums[i]==nums[i-1]: ans |= f(i-2)
            if i>1 and nums[i]==nums[i-1]==nums[i-2]: ans |= f(i-3)
            if i>1 and nums[i]==nums[i-1]+1==nums[i-2]+2: ans |= f(i-3) 
            dp[i] = ans
            return ans
        return f(len(nums)-1)