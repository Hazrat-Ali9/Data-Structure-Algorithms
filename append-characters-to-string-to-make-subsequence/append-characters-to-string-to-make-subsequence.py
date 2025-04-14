class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        i, j = 0 , 0
        while i<len(s):
            if j<len(t) and s[i]==t[j]:
                j+=1
            i += 1
        return len(t)-j