class Solution {
    private int dis(int[] a, int[] b){
        return Math.abs(a[0]-b[0]) + Math.abs(a[1]-b[1]);
    }
    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        int[] minCost = new int[n];
        Arrays.fill(minCost, Integer.MAX_VALUE);
        minCost[0] = 0;
        int[] vis = new int[n];
        int curr = 0, ans = 0;
        while(curr >= 0){
            vis[curr] = 1;
            int minCurr=Integer.MAX_VALUE, nxtPoint = -1;
            for(int i=0; i<n; i++){
                if(curr==i || vis[i]==1) continue;
                minCost[i] = Math.min(dis(points[curr], points[i]), minCost[i]);
                if(minCurr > minCost[i]){
                    minCurr = minCost[i];
                    nxtPoint = i;
                }
            }
            ans += (minCurr == Integer.MAX_VALUE ? 0 : minCurr);
            curr = nxtPoint;
        }
        return ans;
    }
}