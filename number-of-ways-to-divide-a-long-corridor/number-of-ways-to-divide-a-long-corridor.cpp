class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> dp;
    int numberOfWays(string corridor) {
        dp.resize(corridor.size(), vector<int>(3, -1));
        return f(0, 0, corridor);
    }
    int f(int index, int seats, string &s){
        if(index == s.size()) return seats == 2 ? 1 : 0;
        if(dp[index][seats] != -1) return dp[index][seats];
        int ans = 0;
        if(seats == 2){
            if(s[index] == 'S') ans = f(index+1, 1, s);
            else ans = (f(index+1, 0, s) + f(index+1, 2, s)) % mod;
        }
        else{
            if(s[index] == 'S') ans = f(index+1, seats+1, s);
            else ans = f(index+1, seats, s);
        }
        dp[index][seats] = ans;
        return dp[index][seats];
    }
};