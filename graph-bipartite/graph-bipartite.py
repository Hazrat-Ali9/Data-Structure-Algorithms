class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        color = [-1]*len(graph)
        for i in range(0, len(graph)):
            if color[i] == -1:
                if not self.dfs(i, graph, color): return False
        return True
    def dfs(self, src, graph, color):
        q = deque()
        q.append(src)
        color[src] = 1
        while q:
            node = q.popleft()
            for x in graph[node]:
                if color[x] == -1:
                    color[x] = 1 - color[node]
                    q.append(x)
                elif color[x] == color[node]: return False
        return True