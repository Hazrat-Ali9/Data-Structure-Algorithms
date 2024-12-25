class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n = len(profit)
        jobs = []
        for i in range(n):
            jobs.append([startTime[i], endTime[i], profit[i]])
        jobs.sort()
        startTime.sort()
        dp = [-1] * n
        return self.f(0, n, startTime, jobs, dp)
    def f(self, i, n, st, jobs, dp):
        if i >= n: return 0
        if dp[i] != -1: return dp[i]
        ind = self.nextIndex(0, n, jobs[i][1], st)
        pick = jobs[i][2] + self.f(ind, n, st, jobs, dp)
        notPick = self.f(i+1, n, st, jobs, dp)
        dp[i] = max(pick, notPick)
        return dp[i]
    def nextIndex(self, l, n, time, st):
        nxtIn = n
        r = n-1
        while l <= r:
            m = (l+r)//2
            if st[m] >= time:
                nxtIn = m
                r = m-1
            else: l = m+1
        return nxtIn