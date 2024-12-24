class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        if n==1: return 0
        return self.bfs(graph)
    def bfs(self, g):
        n = len(g)
        allMask = (1 << n) - 1
        q = deque()
        s = set()
        for i in range(0, n):
            mask = (1<<i)
            q.append((i, (0, mask)))
            s.add((i, mask))
        while q:
            val, (dis, mask) = q.popleft()
            for nbr in g[val]:
                newMask = (1<<nbr) | mask
                if newMask == allMask: return dis+1
                elif (nbr, newMask) in s: continue
                else:
                    q.append((nbr, (dis+1, newMask)))
                    s.add((nbr, newMask))
        return 0