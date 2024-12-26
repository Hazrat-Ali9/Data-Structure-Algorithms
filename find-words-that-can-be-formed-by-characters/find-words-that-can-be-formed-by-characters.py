class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        mp = [0] * 26
        for c in chars: mp[ord(c)-ord('a')]+=1
        ans = 0
        for s in words:
            cnt = [0] * 26
            for c in s: cnt[ord(c)-ord('a')] += 1
            isValid = True
            for c in s:
                if mp[ord(c)-ord('a')] < cnt[ord(c)-ord('a')]:
                    isValid = False
                    break
            if isValid:
                ans += len(s)
        return ans