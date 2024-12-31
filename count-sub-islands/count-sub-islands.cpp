class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size(), m = grid2[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cntSubIsland = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && isCellLand(i, j, grid2) && isSubIsland(i, j, grid1, grid2, vis)){
                    cntSubIsland++;
                }
            }
        }
        return cntSubIsland;
    }
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isCellLand(int i, int j, vector<vector<int>>&grid){
        return grid[i][j] == 1;
    }
    bool isSubIsland(int x, int y, vector<vector<int>>&grid1, vector<vector<int>>&grid2, vector<vector<bool>>&vis){
        int n = grid2.size(), m = grid2[0].size();
        bool isSubIsland = true;
        queue<pair<int, int>> pendingCells;
        pendingCells.push({x, y});
        vis[x][y] = true;
        while(!pendingCells.empty()){
            int currX = pendingCells.front().first;
            int currY = pendingCells.front().second;
            pendingCells.pop();
            if(!isCellLand(currX, currY, grid1)) isSubIsland = false;
            for(auto d : dir){
                int newX = currX + d[0];
                int newY = currY + d[1];
                if(newX>=0 && newX<n && newY>=0 && newY<m && !vis[newX][newY] && isCellLand(newX, newY, grid2)){
                    pendingCells.push({newX, newY});
                    vis[newX][newY] = true;
                }
            }
        }
        return isSubIsland;
    }
};