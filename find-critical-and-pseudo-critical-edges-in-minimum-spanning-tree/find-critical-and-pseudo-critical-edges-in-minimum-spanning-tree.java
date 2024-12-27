class Solution {
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        int m = edges.length;
        // Add index to edges for tracking
        int[][] newEdges = new int[m][4];
        for(int i=0; i<m; i++){
            for(int j=0; j<3; j++) newEdges[i][j] = edges[i][j];
            newEdges[i][3] = i;
        }
        // Sort edges based on weight
        Arrays.sort(newEdges, Comparator.comparingInt(edge -> edge[2]));
        // Find MST weight using union-find
        UnionFind uf = new UnionFind(n);
        int weight = 0;
        for(int[] edge : newEdges){
            if(uf.union(edge[0], edge[1])) weight += edge[2];
        }
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0; i<2; i++){
            ans.add(new ArrayList<>());
        }
        // Check each edge for critical and pseudo-critical
        for(int i=0; i<m; i++){
            // Ignore this edge and calculate MST weight
            UnionFind ufIgnore = new UnionFind(n);
            int ignoreWeight = 0;
            for(int j=0; j<m; j++){
                if(i!=j && ufIgnore.union(newEdges[j][0], newEdges[j][1])){
                    ignoreWeight += newEdges[j][2];
                }
            }
            // If the graph is disconnected or the total weight is greater, 
            // the edge is critical
            if(ufIgnore.mxSize<n || ignoreWeight>weight){
                ans.get(0).add(newEdges[i][3]);
            }
            else{
                // Force this edge and calculate MST weight
                UnionFind ufForce = new UnionFind(n);
                ufForce.union(newEdges[i][0], newEdges[i][1]);
                int forceWeight = newEdges[i][2];
                for(int j=0; j<m; j++){
                    if(i!=j && ufForce.union(newEdges[j][0], newEdges[j][1])){
                        forceWeight += newEdges[j][2];
                    }
                }
                // If total weight is the same, the edge is pseudo-critical
                if(forceWeight == weight) ans.get(1).add(newEdges[i][3]);
            }
        }
        return ans;
    }
    class UnionFind{
        int[] parent;
        int[] size;
        int mxSize;
        public UnionFind(int n){
            parent = new int[n];
            size = new int[n];
            mxSize = 1;
            for(int i=0; i<n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        public int find(int x){
            if(x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }
        public boolean union(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY){
                if(size[rootX] < size[rootY]){
                    int temp = size[rootX];
                    size[rootX] = size[rootY];
                    size[rootY] = temp;
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                mxSize = Math.max(mxSize, size[rootX]);
                return true;
            }
            return false;
        }
    }
}