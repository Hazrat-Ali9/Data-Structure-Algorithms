class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;
        return bfs(graph);
    }
    int bfs(vector<vector<int>> g){
        int n = g.size();
        int all = (1 << n) - 1;
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> s;
        for(int i=0; i<n; i++){
            int mask = 1<<i;
            q.push({i, {0, mask}});
            s.insert({i, mask});
        }
        while(!q.empty()){
            auto x = q.front(); q.pop();
            int val = x.first, dis = x.second.first, mask = x.second.second;
            for(int nbr : g[val]){
                int newMask = (mask | (1<<nbr));
                if(newMask == all) return dis+1;
                else if(s.count({nbr, newMask})) continue;
                else{
                    q.push({nbr, {dis+1, newMask}});
                    s.insert({nbr, newMask});
                }
            }
        }
        return 0;
    }
};