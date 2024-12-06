class Solution {
    public int maxProfit(int[] prices) {
        int mn = Integer.MAX_VALUE, ans = 0;
        for(int i=0; i<prices.length; i++){
            mn = Math.min(mn, prices[i]);
            ans = Math.max(ans, prices[i] - mn);
        }
        return ans;
    }
}