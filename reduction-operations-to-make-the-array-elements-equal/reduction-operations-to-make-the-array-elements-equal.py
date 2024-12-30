class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort();
        cnt, up = 0, 0
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]: up+=1
            cnt += up
        return cnt