class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        f, s = float(inf), float(inf)
        for x in prices:
            if x < f:
                s = f
                f = x
            else: s = min(s, x)
        return money-s-f if s+f <= money else money