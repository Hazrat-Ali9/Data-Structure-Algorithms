class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Store the topologically sorted sequences.
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderCols = topoSort(colConditions, k);
        //if no topological sort exists, return empty array.
        if(orderRows.empty() or orderCols.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(orderRows[i] == orderCols[j]) matrix[i][j] = orderRows[i];
            }
        }
        return matrix;
    }
    vector<int> topoSort(vector<vector<int>>&edges, int n){
        vector<vector<int>> adj(n+1);
        vector<int> deg(n+1),order;
        //Build adjacency list
        for(auto &x : edges){
            adj[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(deg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            order.push_back(f);
            n--;
            for(auto x : adj[f]){
                if(--deg[x] == 0) q.push(x);
            }
        }
        //If we have not visited all the integer, return empty array
        if(n != 0) return {};
        return order;
    }
};