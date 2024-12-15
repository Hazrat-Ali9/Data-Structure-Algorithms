class Solution {
    public int maxProfit(int[] prices, int fee) {
        int ans = 0, buy = -prices[0];
        for(int i=1; i<prices.length; i++){
            int tmp = buy;
            buy = Math.max(buy, ans - prices[i]);
            ans = Math.max(ans, tmp+prices[i]-fee);
        }
        return ans;
    }
}