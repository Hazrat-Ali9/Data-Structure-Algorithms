class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        q = deque()
        firstX = -1
        firstY = -1
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    firstX = i
                    firstY = j
                    break
            if firstX != -1:
                break
        self.dfs(grid, firstX, firstY, n, q)
        distance = 0
        while q:
            size = len(q)
            for _ in range(size):
                x, y = q.popleft()
                for k in range(4):
                    curX = x + dx[k]
                    curY = y + dy[k]
                    if 0 <= curX < n and 0 <= curY < n:
                        if grid[curX][curY] == 1:
                            return distance
                        elif grid[curX][curY] == 0:
                            q.append((curX, curY))
                            grid[curX][curY] = -1
            distance += 1
        return distance
    def dfs(self, grid, x, y, n, q):
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        grid[x][y] = 2
        q.append((x, y))
        for k in range(4):
            curX = x + dx[k]
            curY = y + dy[k]
            if 0 <= curX < n and 0 <= curY < n and grid[curX][curY] == 1:
                self.dfs(grid, curX, curY, n, q)