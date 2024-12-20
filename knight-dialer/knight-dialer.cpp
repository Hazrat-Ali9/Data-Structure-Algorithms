class Solution {
public:
    vector<vector<int>> dp;
    int n, mod = 1e9+7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int knightDialer(int n) {
        this->n = n;
        dp = vector(n+1, vector(10, 0));
        int ans = 0;
        for(int i=0; i<10; i++){
            ans = (ans + f(n-1, i)) % mod;
        }
        return ans;
    }
    int f(int remain, int square){
        if(remain == 0) return 1;
        if(dp[remain][square] != 0) return dp[remain][square];
        int ans = 0;
        for(int nxtSquare : jumps[square]) ans = (ans + f(remain-1, nxtSquare)) % mod;
        dp[remain][square] = ans;
        return ans;
    }
};