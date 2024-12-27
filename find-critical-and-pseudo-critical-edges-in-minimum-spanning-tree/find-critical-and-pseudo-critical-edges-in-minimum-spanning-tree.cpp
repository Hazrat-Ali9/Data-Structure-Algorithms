class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        auto newEdges = edges;
        int m = newEdges.size();
        // Add index to edges for tracking
        for(int i=0; i<m; i++){
            newEdges[i].push_back(i);
        }
        // Sort edges based on weight
        sort(newEdges.begin(), newEdges.end(), [](auto& a, auto& b){
            return a[2]<b[2];
        });
        // Find MST weight using union-find
        UnionFind uf(n);
        int weight = 0;
        for(auto edge : newEdges){
            if(uf.unite(edge[0], edge[1])) weight += edge[2];
        }
        vector<vector<int>> ans(2);
        // Check each edge for critical and pseudo-critical
        for(int i=0; i<m; i++){
            UnionFind ufIgnore(n);
            int ignoreWeight = 0;
            for(int j=0; j<m; j++){
                if(i != j && ufIgnore.unite(newEdges[j][0], newEdges[j][1])){
                    ignoreWeight += newEdges[j][2];
                }
            }
            // If the graph is disconnected or the total weight is greater, 
            // the edge is critical
            if(ufIgnore.mxSize < n || ignoreWeight > weight){
                ans[0].push_back(newEdges[i][3]);
            }
            else{
                // Force this edge and calculate MST weight
                UnionFind ufForce(n);
                ufForce.unite(newEdges[i][0], newEdges[i][1]);
                int forceWeight = newEdges[i][2];
                for(int j=0; j<m; j++){
                    if(i != j && ufForce.unite(newEdges[j][0], newEdges[j][1])){
                        forceWeight += newEdges[j][2];
                    }
                }
                if(forceWeight == weight){
                    ans[1].push_back(newEdges[i][3]);
                }
            }
        }
        return ans;
    }
    class UnionFind{
        public:
        vector<int> parent;
        vector<int> size;
        int mxSize;
        UnionFind(int n){
            parent.resize(n);
            size.resize(n, 1);
            mxSize = 1;
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }
        int find(int x){
            if(x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY){
                if(size[rootX] < size[rootY]){
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                mxSize = max(mxSize, size[rootX]);
                return true;
            }
            return false;
        }
    };
};