class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        l, r = 1, sum(batteries)//n
        while l < r:
            target = r - (r - l)//2
            extra = 0
            for x in batteries: extra += min(x, target)
            if extra//n >= target: l = target
            else: r = target-1
        return l