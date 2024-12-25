class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt = [0]*26
        for i in range(len(s)):
            cnt[ord(s[i])-ord('a')] += 1
            cnt[ord(t[i])-ord('a')] -= 1
        ans = 0
        for i in range(26):
            ans += max(0, cnt[i])
        return ans