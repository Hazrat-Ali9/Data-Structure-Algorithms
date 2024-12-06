class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s)+1)
        dp[0] = True
        for i in range(0, len(s)+1):
            for word in wordDict:
                if dp[i] and s[i : i+len(word)] == word:
                    dp[i+len(word)]= True
        return dp[len(s)]