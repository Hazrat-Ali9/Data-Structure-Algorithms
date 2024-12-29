class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        for(int[] x : roads){
            adj.computeIfAbsent(x[0], k -> new HashSet<>()).add(x[1]);
            adj.computeIfAbsent(x[1], k -> new HashSet<>()).add(x[0]);
        }
        int mxRank = 0;
        for(int node1=0; node1<n; node1++){
            for(int node2=node1+1; node2<n; node2++){
                int currRank = adj.getOrDefault(node1, Collections.emptySet()).size() + 
                    adj.getOrDefault(node2, Collections.emptySet()).size();
                if(adj.getOrDefault(node1, Collections.emptySet()).contains(node2)){
                    currRank--;
                }
                mxRank = Math.max(mxRank, currRank);
            }
        }
        return mxRank;
    }
}