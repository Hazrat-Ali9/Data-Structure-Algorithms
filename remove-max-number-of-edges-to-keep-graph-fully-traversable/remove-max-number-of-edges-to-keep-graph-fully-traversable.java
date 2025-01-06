class DSU{
    int[] parent, rank;
    public DSU(int n){
        parent = new int[n];
        rank = new int[n];
        for(int i=0; i<n; i++) parent[i] = i;
    }
    public int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    public boolean union(int x, int y){
        int xSet = find(x), ySet = find(y);
        if(xSet != ySet){
            if(rank[xSet] < rank[ySet]) parent[xSet] = ySet;
            else if(rank[xSet] > rank[ySet]) parent[ySet] = xSet;
            else{
                parent[ySet] = xSet;
                rank[xSet]++;
            }
            return true;
        }
        return false;
    }
}
class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        Arrays.sort(edges, (a, b) -> Integer.compare(b[0], a[0]));
        DSU alice = new DSU(n+1);
        DSU bob = new DSU(n+1);
        int removedEdge = 0, aliceEdge = 0, bobEdge = 0;
        for(int[] edge : edges){
            if(edge[0] == 3){
                if(alice.union(edge[1], edge[2])){
                    bob.union(edge[1], edge[2]);
                    aliceEdge++;
                    bobEdge++;
                }
                else removedEdge++;
            }
            else if(edge[0]==2){
                if(bob.union(edge[1], edge[2])) bobEdge++;
                else removedEdge++;
            }
            else{
                if(alice.union(edge[1], edge[2])) aliceEdge++;
                else removedEdge++;
            }
        }
        return (bobEdge == n-1 && aliceEdge==n-1) ? removedEdge : -1;
    }
}