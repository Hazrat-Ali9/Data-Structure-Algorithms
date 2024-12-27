class Solution:
    def countOrders(self, n: int) -> int:
        places, cnt, mod = 2*n, 1, 1e9+7
        for i in range(n, 0, -1):
            cnt = (cnt*((places*(places-1))//2))%mod
            places -= 2
        return int(cnt)