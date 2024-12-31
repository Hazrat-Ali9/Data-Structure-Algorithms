class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        if k==0: return nums
        n = len(nums)
        avg = [-1] * n
        if 2*k+1 > n: return avg
        prefSum = [0] * (n+1)
        for i in range(n): prefSum[i+1] = prefSum[i] + nums[i]
        for i in range(k, n-k):
            subArraySum = prefSum[i+k+1] - prefSum[i-k]
            average = subArraySum // (2*k+1)
            avg[i] = average
        return avg