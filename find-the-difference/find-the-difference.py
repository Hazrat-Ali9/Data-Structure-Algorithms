class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ans = 0
        for x in s: ans ^= ord(x)
        for x in t: ans ^= ord(x)
        return chr(ans)