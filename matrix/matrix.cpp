class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[][] ans = new int[n][m];
        for(int[] row : ans) Arrays.fill(row, -1);
        Queue<int[]> q = new LinkedList<>();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.offer(new int[] {i, j});
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!q.isEmpty()){
            int[] it = q.poll();
            int x = it[0], y = it[1];
            for(int k=0; k<4; k++){
                int r = x+dx[k];
                int c = y+dy[k];
                if(r>=0 && r<n && c>=0 && c<m && ans[r][c]==-1){
                    ans[r][c] = ans[x][y]+1;
                    q.offer(new int[] {r, c});
                }
            }
        }
        return ans;
    }
}