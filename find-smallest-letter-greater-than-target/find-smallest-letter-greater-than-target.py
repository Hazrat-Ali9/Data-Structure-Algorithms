class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l, r = 0, len(letters)-1
        while l <= r:
            m = (l+r)//2
            if letters[m] <= target: l = m+1
            else: r = m-1
        if l == len(letters): return letters[0]
        return letters[l]