class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt = 0, n = grid.size();
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                bool match = true;
                for(int i=0; i<n; i++){
                    if(grid[r][i] != grid[i][c]){
                        match = false;
                        break;
                    }
                }
                cnt += match ? 1 : 0;
            }
        }
        return cnt;
    }
};