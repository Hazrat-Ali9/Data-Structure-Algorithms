class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        smallest, biggest, ans = arrays[0][0], arrays[0][-1], 0
        for i in range(1, len(arrays)):
            ans = max(ans, abs(arrays[i][-1]-smallest), abs(biggest - arrays[i][0]))
            smallest = min(smallest, arrays[i][0])
            biggest = max(biggest, arrays[i][-1])
        return ans