class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> rowCnt(n, 0), colCnt(m, 0);
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
};