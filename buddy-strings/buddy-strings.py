class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal): return False
        if s == goal:
            freq = [0] * 26
            for ch in s:
                freq[ord(ch) - ord('a')] += 1
                if freq[ord(ch) - ord('a')] == 2: return True
            return False
        fIndex = -1
        sIndex = -1
        for i in range(len(s)):
            if s[i] != goal[i]:
                if fIndex == -1: fIndex = i
                elif sIndex == -1: sIndex = i
                else: return False
        if sIndex == -1: return False
        return s[fIndex] == goal[sIndex] and s[sIndex] == goal[fIndex]