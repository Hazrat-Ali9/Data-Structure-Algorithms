class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto edge : adjacentPairs){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int root = 0;
        for(auto pair : graph){
            if(pair.second.size() == 1){
                root = pair.first;
                break;
            }
        }
        vector<int> ans;
        dfs(root, INT_MAX, ans);
        return ans;
    }
    void dfs(int node, int prev, vector<int>&ans){
        ans.push_back(node);
        for(int nei : graph[node]){
            if(nei != prev) dfs(nei, node, ans);
        }
    }
};