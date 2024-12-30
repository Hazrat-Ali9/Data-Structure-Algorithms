class Solution {
    public int minimumEffortPath(int[][] heights) {
        int n = heights.length, m = heights[0].length, ans = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[]{0, 0, 0});
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        while(pq.size()!=0){
            int[] x = pq.poll();
            ans = Math.max(ans, x[0]);
            int i=x[1], j=x[2];
            if(heights[i][j]==-1) continue;
            if(i==n-1 && j==m-1) break;
            for(int k=0; k<4; k++){
                int row = i+dx[k], col = j+dy[k];
                if(row<0 || row>=n || col<0 || col>=m || heights[row][col]==-1) continue;
                pq.add(new int[]{Math.abs(heights[i][j]-heights[row][col]), row, col});
            }
            heights[i][j] = -1;
        }
        return ans;
    }
}