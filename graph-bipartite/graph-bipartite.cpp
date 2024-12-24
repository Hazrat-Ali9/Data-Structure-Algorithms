class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(color[i] == -1){
                if(!bfs(i, graph, color)) return false;
            }
        }
        return true;
    }
    bool bfs(int src, vector<vector<int>>& graph, vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x : graph[node]){
                if(color[x] == -1){
                    color[x] = 1 - color[node];
                    q.push(x);
                }
                else if(color[x] == color[node]) return false;
            }
        }
        return true;
    }
};