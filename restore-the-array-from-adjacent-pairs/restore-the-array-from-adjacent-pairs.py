class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        for x, y in adjacentPairs:
            graph[x].append(y)
            graph[y].append(x)
        root = None
        for num in graph:
            if len(graph[num]) == 1:
                root = num
                break
        def dfs(node, prev, ans):
            ans.append(node)
            for nei in graph[node]:
                if nei != prev: dfs(nei, node, ans)
        ans = []
        dfs(root, None, ans)
        return ans