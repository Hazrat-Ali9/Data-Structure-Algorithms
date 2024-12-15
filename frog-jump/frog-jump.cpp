class Solution {
public:
    unordered_map<int, int> mp;
    int dp[2001][2001];
    bool canCross(vector<int>& stones) {
        for(int i=0; i<stones.size(); i++) mp.insert({stones[i], i});
        memset(dp, -1, sizeof(dp));
        return f(stones, stones.size(), 0, 0);
    }
    int f(vector<int> &stones, int n, int i, int prevJump){
        if(i == n-1) return 1;
        if(dp[i][prevJump] != -1) return dp[i][prevJump];
        int ans = false;
        for(int k=prevJump-1; k<=prevJump+1; k++){
            if(k>0 && mp.find(stones[i]+k) != mp.end()){
                ans = ans || f(stones, n, mp[stones[i]+k], k);
            }
        }
        return dp[i][prevJump] = ans;
    }
};