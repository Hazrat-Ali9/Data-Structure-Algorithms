class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        cnt1, cnt2 = [0]*26, [0]*26
        for c in word1:
            cnt1[ord(c)-ord('a')]+=1
        for c in word2:
            cnt2[ord(c)-ord('a')]+=1
        for i in range(26):
            if (cnt1[i]==0 and cnt2[i]!=0) or (cnt1[i]!=0 and cnt2[i]==0): return False
        cnt1.sort()
        cnt2.sort()
        return cnt1==cnt2