class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n, m, ans = len(heights), len(heights[0]), 0
        pq = [(0, 0, 0)]
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        while pq:
            effort, i, j = heapq.heappop(pq)
            ans = max(ans, effort)
            if heights[i][j]==-1: continue
            if i==n-1 and j==m-1: break
            for k in range(4):
                row, col = i+dx[k], j+dy[k]
                if row<0 or row>=n or col<0 or col>=m or heights[row][col]==-1: continue
                heapq.heappush(pq, (abs(heights[i][j] - heights[row][col]), row, col))
            heights[i][j] = -1
        return ans