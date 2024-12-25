class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> graph;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            graph[u].push_back({v, pathProb});
            graph[v].push_back({u, pathProb});
        }
        vector<double> mxProb(n);
        mxProb[start_node] = 1.0;
        queue<int> q;
        q.push(start_node);
        while(!q.empty()){
            int currNode = q.front(); q.pop();
            for(auto x : graph[currNode]){
                int nxtNode = x.first;
                double pathProb = x.second;
                if(mxProb[currNode]*pathProb > mxProb[nxtNode]){
                    mxProb[nxtNode] = mxProb[currNode] * pathProb;
                    q.push(nxtNode);
                }
            }
        }
        return mxProb[end_node];
    }
};