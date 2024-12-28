class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(num):
            res = 0
            while num:
                res = res * 10 + num % 10
                num //= 10
            return res
        arr = []
        for i in range(len(nums)):
            arr.append(nums[i]-rev(nums[i]))
        mp = defaultdict(int)
        ans, mod = 0, 10**9+7
        for x in arr:
            ans = (ans + mp[x]) % mod
            mp[x] += 1
        return ans