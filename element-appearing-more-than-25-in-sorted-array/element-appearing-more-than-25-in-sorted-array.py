class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        cnt = defaultdict(int)
        target = len(arr)/4
        for x in arr:
            cnt[x] += 1
            if cnt[x] > target: return x
        return -1