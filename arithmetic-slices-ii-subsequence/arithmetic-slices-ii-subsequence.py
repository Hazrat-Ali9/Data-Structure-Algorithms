class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans = 0
        cnt = [defaultdict(int) for _ in range(len(nums))]
        for i in range(1, len(nums)):
            for j in range(i):
                delta = nums[i] - nums[j]
                sum_count = 0
                if delta in cnt[j]:
                    sum_count = cnt[j][delta]
                cnt[i][delta] += sum_count + 1
                ans += sum_count
        return ans