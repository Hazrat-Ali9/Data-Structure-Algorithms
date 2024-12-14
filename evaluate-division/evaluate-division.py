class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        ans = []
        graph = defaultdict(dict)
        for i in range(len(equations)):
            a, b = equations[i]
            value = values[i]
            graph[a][b] = value
            graph[b][a] = 1.0 / value
        for query in queries:
            a, b = query
            visited = set()
            result = self.dfs(a, b, graph, visited)
            if result != 0.0:
                ans.append(result)
            else:
                ans.append(-1.0)
        return ans
    def dfs(self, a, b, graph, visited):
        if a not in graph or b not in graph:
            return 0.0
        if b in graph[a]:
            return graph[a][b]
        visited.add(a)
        for node, value in graph[a].items():
            if node not in visited:
                result = self.dfs(node, b, graph, visited)
                if result != 0.0:
                    graph[a][b] = value * result
                    return graph[a][b]
        return 0.0