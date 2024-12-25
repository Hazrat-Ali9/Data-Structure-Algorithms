class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        ans = 0
        while a or b or c:
            if c&1:
                ans += 0 if ((a&1) or (b&1)) else 1
            else: ans += (a&1) + (b&1)
            a >>= 1
            b >>= 1
            c >>= 1
        return ans