class Solution {
public:
    int mod = 1e9+7, n, m;
    vector<vector<vector<int>>> dp;
    int numOfArrays(int n, int m, int k) {
        dp = vector(n, vector(m+1, vector(k+1, -1)));
        this->n = n;
        this->m = m;
        return f(0, 0, k);
    }
    int f(int i,int mxSoFar, int remain){
        if(i == n){
            if(remain == 0) return 1;
            return 0;
        }
        if(remain < 0) return 0;
        if(dp[i][mxSoFar][remain] != -1) return dp[i][mxSoFar][remain];
        int ans = 0;
        for(int num=1; num<=mxSoFar; num++){
            ans = (ans + f(i+1, mxSoFar, remain)) % mod;
        }
        for(int num=mxSoFar+1; num<=m; num++){
            ans = (ans + f(i+1, num, remain-1)) % mod;
        }
        dp[i][mxSoFar][remain] = ans;
        return ans;
    }
};