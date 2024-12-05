class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1)+len(s2) != len(s3): return False
        dp = [[-1]*(len(s2)+1) for _ in range(len(s1)+1)]
        return self.f(0, 0, s1, s2, s3, dp)
    def f(self, i, j, s1, s2, s3, dp):
        if i+j == len(s3): return True
        if dp[i][j] != -1: return dp[i][j]
        ans = 0
        if i < len(s1) and s1[i]==s3[i+j]: ans |= self.f(i+1, j, s1, s2, s3, dp)
        if j < len(s2) and s2[j]==s3[i+j]: ans |= self.f(i, j+1, s1, s2, s3, dp)
        dp[i][j] = ans
        return ans