class Solution {
    public boolean isBipartite(int[][] graph) {
        int[] color = new int[graph.length];
        Arrays.fill(color, -1);
        for(int i=0; i<graph.length; i++){
            if(color[i] == -1){
                if(!dfs(i, graph, color)) return false;
            }
        }
        return true;
    }
    boolean dfs(int src, int[][] graph, int[] color){
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        color[src] = 1;
        while(!q.isEmpty()){
            int node = q.poll();
            for(int x : graph[node]){
                if(color[x] == -1){
                    color[x] = 1 - color[node];
                    q.add(x);
                }
                else if(color[x] == color[node]) return false;
            }
        }
        return true;
    }
}