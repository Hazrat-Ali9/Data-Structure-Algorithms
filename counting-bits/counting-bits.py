class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [] * (n+1)
        for i in range(n+1):
            cnt, num = 0, i
            while num > 0:
                cnt += num%2
                num = num//2
            ans.append(cnt)
        return ans