class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        n = len(nums)
        totalSum = sum(nums)
        leftSum = 0
        ans = []
        for i in range(n):
            rightSum = totalSum - leftSum - nums[i]
            
            leftCnt, rightCnt = i, n-1-i
            
            leftTotal = leftCnt * nums[i] - leftSum
            rightTotal = rightSum - rightCnt * nums[i]
            
            ans.append(leftTotal+rightTotal)
            leftSum += nums[i]
        return ans