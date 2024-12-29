class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank = 0;
        unordered_map<int, unordered_set<int>> adj;
        for(auto x : roads){
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
        }
        for(int node1=0; node1<n; node1++){
            for(int node2=node1+1; node2<n; node2++){
                int currRank = adj[node1].size() + adj[node2].size();
                if(adj[node1].find(node2) != adj[node1].end()) currRank--;
                maxRank = max(maxRank,currRank);
            }
        }
        return maxRank;
    }
};