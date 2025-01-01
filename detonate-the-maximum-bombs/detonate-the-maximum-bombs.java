class Solution {
    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;
        List<List<Integer>> graph = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            long x1, y1, r1;
            x1 = bombs[i][0];
            y1 = bombs[i][1];
            r1 = bombs[i][2];
            graph.add(new ArrayList<>());
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    long x, y;
                    x = Math.abs(bombs[j][0] - x1);
                    y = Math.abs(bombs[j][1] - y1);
                    if(x*x + y*y <= r1*r1) {
                        graph.get(i).add(j);
                    }
                }
            }
        }
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int[] cnt = new int[1];
            boolean[] vis = new boolean[n];
            dfs(graph, vis, cnt, i);
            ans = Math.max(ans, cnt[0]);
        }
        return ans;
    }
    void dfs(List<List<Integer>> graph, boolean[] vis, int[] cnt, int i) {
        vis[i] = true;
        cnt[0]++;
        for (int j = 0; j < graph.get(i).size(); j++) {
            if (!vis[graph.get(i).get(j)]) {
                dfs(graph, vis, cnt, graph.get(i).get(j));
            }
        }
    }
}