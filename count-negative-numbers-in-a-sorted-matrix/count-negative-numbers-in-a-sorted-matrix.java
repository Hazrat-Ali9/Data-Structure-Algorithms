class Solution {
    public int countNegatives(int[][] grid) {
        int cnt = 0;
        int n = grid[0].length;
        for(int[] row : grid){
            int l = 0, r = n-1;
            while(l <= r){
                int m = (l + r) / 2;
                if(row[m] < 0) r = m-1;
                else l = m+1;
            }
            cnt += (n - l);
        }
        return cnt;
    }
}