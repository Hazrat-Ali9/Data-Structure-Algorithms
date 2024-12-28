class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        def check(arr):
            mn, mx = min(arr), max(arr)
            if (mx-mn) % (len(arr)-1) != 0: return False
            diff = (mx - mn) / (len(arr)-1)
            s = set(arr)
            curr = mn + diff
            while curr < mx:
                if curr not in s: return False
                curr += diff
            return True
        ans = []
        for i in range(len(l)):
            arr = nums[l[i] : r[i]+1]
            ans.append(check(arr))
        return ans