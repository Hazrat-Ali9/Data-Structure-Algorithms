class Solution {
    HashMap<Integer, Integer> mp = new HashMap<>();
    int[][] dp = new int[2001][2001];
    public boolean canCross(int[] stones) {
        for(int i=0; i<stones.length; i++) mp.put(stones[i], i);
        for(int[] row : dp) Arrays.fill(row, -1);
        return f(stones, stones.length, 0, 0);
    }
    boolean f(int[] stones, int n, int i, int prevJump){
        if(i == n-1) return true;
        if(dp[i][prevJump] != -1) return dp[i][prevJump] == 1;
        boolean ans = false;
        for(int k=prevJump-1; k<=prevJump+1; k++){
            if(k > 0 && mp.containsKey(stones[i]+k)){
                ans = ans || f(stones, n, mp.get(stones[i]+k), k);
            }
        }
        dp[i][prevJump] = ans ? 1 : 0;
        return ans;
    }
}