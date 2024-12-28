class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        n, m = len(word1), len(word2)
        i, j, x, y = 0, 0, 0, 0
        while i<n and j<m:
            if word1[i][x] != word2[j][y]: return False
            x += 1
            y += 1
            if len(word1[i]) == x:
                i+=1
                x=0
            if len(word2[j])== y:
                j+=1
                y=0
        return i==n and j==m