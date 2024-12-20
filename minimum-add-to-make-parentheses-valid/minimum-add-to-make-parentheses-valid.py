class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        a, b = 0, 0
        for c in s:
            if c == '(':
                a+=1
            else:
                if a > 0: a-=1
                else: b += 1
        return a+b