class Solution {
    public int[][] transpose(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int[][] ans = new int[m][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
}