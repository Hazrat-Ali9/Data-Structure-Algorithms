class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int n = grid.length, m = grid[0].length, ans = 0;
        for(int i=0; i+2<n; i++){
            for(int j=0; j+2<m; j++){
                if(isMagicSquare(grid, i, j)) ans++;
            }
        }
        return ans;
    }
    boolean isMagicSquare(int[][] grid, int r, int c){
        boolean[] seen = new boolean[10];
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int num = grid[r+i][c+j];
                if(num<1 || num>9) return false;
                if(seen[num]) return false;
                seen[num] = true;
            }
        }
        //Check if Diagonal sum are same
        int diagonal1 = grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2];
        int diagonal2 = grid[r+2][c]+grid[r+1][c+1]+grid[r][c+2];
        if(diagonal1 != diagonal2) return false;
        //Check if all row sums are the same as the diagonal sums
        int row1 = grid[r][c]+grid[r][c+1]+grid[r][c+2];
        int row2 = grid[r+1][c]+grid[r+1][c+1]+grid[r+1][c+2];
        int row3 = grid[r+2][c]+grid[r+2][c+1]+grid[r+2][c+2];
        if(!(row1==diagonal1 && row2==diagonal1 && row3==diagonal1)) return false;
        //Check if all col sums are the same as diagonal sums
        int col1 = grid[r][c]+grid[r+1][c]+grid[r+2][c];
        int col2 = grid[r][c+1]+grid[r+1][c+1]+grid[r+2][c+1];
        int col3 = grid[r][c+2]+grid[r+1][c+2]+grid[r+2][c+2];
        if(!(col1==diagonal1 && col2==diagonal1 && col3==diagonal1)) return false;
        return true;
    }
}