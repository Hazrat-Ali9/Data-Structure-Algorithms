class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [-1] * (target+1)
        def f(target):
            if target==0: return 1
            if dp[target]!=-1: return dp[target]
            dp[target] = 0
            for x in nums:
                if x <= target:
                    dp[target] += f(target-x)
            return dp[target]
        return f(target)