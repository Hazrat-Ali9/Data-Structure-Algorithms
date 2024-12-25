class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        maxReach = [0] * (n+1)
        for i in range(0, len(ranges)):
            start = max(0, i-ranges[i])
            end = min(n, i+ranges[i])
            maxReach[start] = max(maxReach[start], end)
        taps, currEnd, nextEnd =0, 0, 0
        for i in range(0, n+1):
            if i > nextEnd:
                return -1
            if i > currEnd:
                taps+=1
                currEnd = nextEnd
            nextEnd = max(nextEnd, maxReach[i])
        return taps