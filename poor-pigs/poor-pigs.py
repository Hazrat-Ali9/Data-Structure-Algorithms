class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        pigs = 0
        while (minutesToTest//minutesToDie+1) ** pigs < buckets:
            pigs += 1
        return pigs