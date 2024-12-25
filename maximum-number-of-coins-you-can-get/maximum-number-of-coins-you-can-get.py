class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        ans = 0
        for i in range(len(piles)//3, len(piles), 2):
            ans += piles[i]
        return ans