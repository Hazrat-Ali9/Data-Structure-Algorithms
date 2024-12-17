class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        ans = [[-1]*m for _ in range(n)]
        q = deque()
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    ans[i][j] = 0
                    q.append((i, j))
        dx = [1, -1, 0, 0]
        dy = [0, 0, -1, 1]
        while q:
            x, y = q.popleft()
            for k in range(4):
                r = x + dx[k]
                c = y + dy[k]
                if r>=0 and r<n and c>=0 and c<m and ans[r][c]==-1:
                    ans[r][c] = ans[x][y]+1
                    q.append((r, c))
        return ans