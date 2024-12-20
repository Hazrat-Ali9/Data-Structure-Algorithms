class Solution {
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    Queue<int[]> q = new LinkedList<>();
    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        int firstX = -1, firstY = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
        }
        dfs(grid, firstX, firstY, n);
        int distance = 0;
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int[] p = q.poll();
                int x = p[0];
                int y = p[1];
                for(int k = 0; k < 4; k++) {
                    int curX = x + dx[k];
                    int curY = y + dy[k];
                    if(0 <= curX && curX < n && 0 <= curY && curY < n) {
                        if(grid[curX][curY] == 1) {
                            return distance;
                        } else if(grid[curX][curY] == 0) {
                            q.offer(new int[]{curX, curY});
                            grid[curX][curY] = -1;
                        }
                    }
                }
            }
            distance++;
        }
        return distance;
    }
    void dfs(int[][] grid, int x, int y, int n){
        grid[x][y] = 2;
        q.offer(new int[]{x, y});
        for(int k=0; k<4; k++){
            int curX = x+dx[k];
            int curY = y+dy[k];
            if(0<=curX && curX<n && 0<=curY && curY<n && grid[curX][curY]==1){
                dfs(grid, curX, curY, n);
            }
        }
    }
    
}