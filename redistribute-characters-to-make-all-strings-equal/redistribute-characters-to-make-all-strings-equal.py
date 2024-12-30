class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt = [0] * 26
        for word in words:
            for c in word:
                cnt[ord(c)-ord('a')]+=1
        n = len(words)
        for x in cnt:
            if x % n != 0:
                return False
        return True