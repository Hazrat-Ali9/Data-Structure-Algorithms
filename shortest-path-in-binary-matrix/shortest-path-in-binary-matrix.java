class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        if (grid[0][0] == 1) return -1;
        if (grid[0][0] == 0 && n == 1 && m == 1) return 1;
        
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 1});
        
        boolean[][] visited = new boolean[n][m];
        visited[0][0] = true;
        
        int[] dx = {1, -1, 0, 0, 1, -1, -1, 1};
        int[] dy = {0, 0, 1, -1, -1, -1, 1, 1};
        
        while (!queue.isEmpty()) {
            int[] pos = queue.poll();
            int x = pos[0];
            int y = pos[1];
            int lenOfPath = pos[2];
            
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0 && !visited[nx][ny]) {
                    queue.offer(new int[]{nx, ny, lenOfPath + 1});
                    visited[nx][ny] = true;
                    
                    if (nx == n - 1 && ny == m - 1)
                        return lenOfPath + 1;
                }
            }
        }
        return -1;
    }
}