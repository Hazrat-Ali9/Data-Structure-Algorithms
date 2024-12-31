class Solution {
    Map<Integer, List<Integer>> graph = new HashMap();
    public int[] restoreArray(int[][] adjacentPairs) {
        for(int[] edge : adjacentPairs){
            graph.computeIfAbsent(edge[0], k -> new ArrayList()).add(edge[1]);
            graph.computeIfAbsent(edge[1], k -> new ArrayList()).add(edge[0]);
        }
        int root = 0;
        for(int num : graph.keySet()){
            if(graph.get(num).size() == 1){
                root = num;
                break;
            }
        }
        int[] ans = new int[graph.size()];
        dfs(root, Integer.MAX_VALUE, ans, 0);
        return ans;
    }
    void dfs(int node, int prev, int[] ans, int i){
        ans[i] = node;
        for(int nei : graph.get(node)){
            if(nei != prev) dfs(nei, node, ans, i+1);
        }
    }
}