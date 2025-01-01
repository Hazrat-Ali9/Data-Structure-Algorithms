class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++){
            long long x1, y1, r1;
            x1 = bombs[i][0];
            y1 = bombs[i][1];
            r1 = bombs[i][2];
            for(int j=0; j<n; j++){
                if(i != j){
                    long long x, y;
                    x = abs(bombs[j][0]-x1);
                    y = abs(bombs[j][1]-y1);
                    if(x*x + y*y <= r1*r1){
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int cnt = 0;
            vector<bool> vis(n, false);
            dfs(graph, vis, cnt, i);
            ans = max(ans, cnt);
        }
        return ans;
    }
    void dfs(vector<vector<int>>&graph, vector<bool>&vis, int &cnt, int &i){
        vis[i] = true;
        cnt++;
        for(int j=0; j<graph[i].size(); j++){
            if(!vis[graph[i][j]]) dfs(graph, vis, cnt, graph[i][j]);
        }
    }
};