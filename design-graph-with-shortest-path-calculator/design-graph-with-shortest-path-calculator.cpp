class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &edge : edges) adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    
    int shortestPath(int node1, int node2) {
        int n = adj.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> costForNode(n, INT_MAX);
        costForNode[node1] = 0;
        pq.push({0, node1});
        while(!pq.empty()){
            int currCost = pq.top()[0];
            int currNode = pq.top()[1];
            pq.pop();
            if(currCost > costForNode[currNode]) continue;
            if(currNode == node2) return currCost;
            for(auto &nei : adj[currNode]){
                int neiNode = nei.first;
                int cost = nei.second;
                int newCost = currCost + cost;
                if(newCost < costForNode[neiNode]){
                    costForNode[neiNode] = newCost;
                    pq.push({newCost, neiNode});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */