class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int l=0, r = piles.size()-2, ans = 0;
        while(l < r){
            ans += piles[r];
            r -= 2;
            l++;
        }
        return ans;
    }
};