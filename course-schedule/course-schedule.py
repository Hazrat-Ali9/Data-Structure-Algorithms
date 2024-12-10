class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inDeg = [0] * numCourses
        adj = [[] for _ in range(numCourses)]
        for x in prerequisites:
            adj[x[1]].append(x[0])
            inDeg[x[0]] += 1
        q = deque()
        for i in range(numCourses):
            if inDeg[i] == 0: q.append(i)
        vis = 0
        while q:
            node = q.popleft()
            vis += 1
            for neighbor in adj[node]:
                inDeg[neighbor] -= 1
                if inDeg[neighbor] == 0:
                    q.append(neighbor)
        return vis == numCourses