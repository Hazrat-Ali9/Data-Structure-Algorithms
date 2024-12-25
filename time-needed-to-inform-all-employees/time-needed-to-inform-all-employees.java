class Solution {
    int maxTime = Integer.MIN_VALUE;
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(n);
        for(int i=0; i<n; i++) adj.add(new ArrayList<Integer>());
        for(int i=0; i<n; i++){
            if(manager[i] != -1) adj.get(manager[i]).add(i);
        }
        dfs(adj, informTime, headID, 0);
        return maxTime;
    }
    void dfs(ArrayList<ArrayList<Integer>> adj, int[] informTime, int curr, int time){
        maxTime = Math.max(maxTime, time);
        for(int x : adj.get(curr)) dfs(adj, informTime, x, time + informTime[curr]);
    }
}