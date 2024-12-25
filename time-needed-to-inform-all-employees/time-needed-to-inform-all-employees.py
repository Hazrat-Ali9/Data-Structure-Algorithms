class Solution:
    maxTime = float('-inf')
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        adj  = [[] for _ in range(n)]
        for i in range(n):
            if manager[i] != -1:
                adj[manager[i]].append(i)
        self.dfs(adj, informTime, headID, 0)
        return self.maxTime
    def dfs(self, adj, informTime, curr, time):
        self.maxTime = max(self.maxTime, time)
        for x in adj[curr]:
                self.dfs(adj, informTime, x, time+informTime[curr])