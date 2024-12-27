class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        mn, mx = min(arr), max(arr)
        n = len(arr)
        if mx - mn == 0: return True
        if (mx - mn) % (n-1) != 0: return False
        diff = (mx - mn) // (n-1)
        s = set()
        for i in range(n):
            if (arr[i] - mn) % diff != 0: return False
            s.add(arr[i])
        return len(s) == n;