class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        vis = [False] * n
        cnt = 0
        for i in range(n):
            if not vis[i]:
                cnt += 1
                self.dfs(i, isConnected, vis)
        return cnt
    def dfs(self, node, isConnected, vis):
        vis[node] = True
        for i in range(len(isConnected)):
            if not vis[i] and isConnected[node][i]: self.dfs(i, isConnected, vis)