class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        ans = n
        arr = sorted(set(nums))
        for i in range(len(arr)):
            l = arr[i]
            r = l+n-1
            j = bisect_right(arr, r)
            cnt = j-i
            ans = min(ans, n-cnt)
        return ans