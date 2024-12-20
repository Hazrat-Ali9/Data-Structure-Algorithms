class Solution {
    int n;
    int[] vis;
    public int removeStones(int[][] stones) {
        n = stones.length;
        vis = new int[n];
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 1) continue;
            cnt++;
            dfs(i, stones);
        }
        return n - cnt;
    }
    void dfs(int ind, int[][] stones){
        vis[ind] = 1;
        for(int i=0; i<n; i++){
            if(vis[i] == 1) continue;
            if(stones[ind][0]==stones[i][0] || stones[ind][1]==stones[i][1]){
                dfs(i, stones);
            }
        }
    }
}