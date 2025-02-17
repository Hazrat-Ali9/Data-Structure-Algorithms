class Solution {
    public long maximumImportance(int n, int[][] roads) {
        long[] deg = new long[n];
        for(int[] edge : roads){
            deg[edge[0]]++;
            deg[edge[1]]++;
        }
        Arrays.sort(deg);
        long val = 1, ans = 0;
        for(long d : deg){
            ans += (val*d);
            val++;
        }
        return ans;
    }
}