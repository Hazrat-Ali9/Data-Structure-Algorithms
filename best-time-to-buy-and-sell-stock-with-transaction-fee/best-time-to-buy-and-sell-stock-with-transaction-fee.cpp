class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans = 0, buy = -prices[0];
        for(int i=1; i<prices.size(); i++){
            int tmp = buy;
            buy = max(buy, ans-prices[i]);
            ans = max(ans, tmp+prices[i]-fee);
        }
        return ans;
    }
};