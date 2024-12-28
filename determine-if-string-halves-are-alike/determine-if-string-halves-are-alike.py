class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])
        i, j, cnt = 0, len(s)//2, 0
        while j < len(s):
            if s[i] in vowels:
                cnt += 1
            if s[j] in vowels:
                cnt -= 1
            i += 1
            j += 1
        return cnt == 0