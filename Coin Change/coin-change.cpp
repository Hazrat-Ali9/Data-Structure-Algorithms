//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int dp[1001][1001];
    long long int count(int coins[], int N, int sum) {
        // code here.
        memset(dp, -1, sizeof(dp));
        return f(N-1, sum, coins);
    }
    long long int f(int i, int sum, int coins[]){
        if(sum == 0) return 1;
        if(i < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        if(sum < coins[i]) return dp[i][sum] = f(i-1, sum, coins);
        long long int take = f(i, sum-coins[i], coins);
        long long int skip = f(i-1, sum, coins);
        return dp[i][sum] = take+skip;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends