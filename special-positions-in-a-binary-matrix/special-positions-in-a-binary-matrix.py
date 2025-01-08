class Solution {
    public int numSpecial(int[][] mat) {
        int n=mat.length, m = mat[0].length;
        int[] rowCnt = new int[n];
        int[] colCnt = new int[m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    if(rowCnt[i]==1 && colCnt[j]==1) ans++;
                }
            }
        }
        return ans;
    }
}