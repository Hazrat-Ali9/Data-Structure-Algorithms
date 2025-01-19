class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        dp = [0]*len(questions)
        return self.solve(0, questions, dp)
    def solve(self, index, questions, dp):
        if index >= len(questions): return 0
        if dp[index] != 0: return dp[index]
        takeIt = questions[index][0] + self.solve(index+questions[index][1]+1, questions, dp);
        leaveIt = self.solve(index+1, questions, dp)
        dp[index] = max(takeIt, leaveIt)
        return dp[index]