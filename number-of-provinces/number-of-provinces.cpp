class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numbersOfComponents = 0;
        vector<bool> vis(n);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                numbersOfComponents++;
                dfs(i, isConnected, vis);
            }
        }
        return numbersOfComponents;
    }
    void dfs(int node, vector<vector<int>>&isConnected, vector<bool>&vis){
        vis[node] = true;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[node][i] && !vis[i]) dfs(i, isConnected, vis);
        }
    }
};