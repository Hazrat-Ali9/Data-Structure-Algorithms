class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0]==1) return -1;
        if(grid[0][0]==0 && n==1 && m==1) return 1;
        queue<pair<pair<int, int>, int>>q;
        q.push({{0,0},1});
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        vis[0][0] = true;
        
        int dx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
        int dy[8] = {0, 0, 1, -1, -1, -1, 1, 1};
        
        while(!q.empty()){
            pair<int, int> p = q.front().first;
            int x = p.first;
            int y = p.second;
            int lenOfPath = q.front().second;
            q.pop();
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0 && !vis[nx][ny])
                {
                    q.push({{nx, ny}, lenOfPath+1});
                    vis[nx][ny] = true;
                    if(nx == n-1 && ny == m-1)
                        return lenOfPath+1;
                }
            }
        }
        return -1;
    }
};