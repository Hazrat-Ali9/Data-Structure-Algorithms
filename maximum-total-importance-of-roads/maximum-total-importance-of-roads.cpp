class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> deg(n, 0);
        for(vector<int> &edge : roads){
            deg[edge[0]]++;
            deg[edge[1]]++;
        }
        sort(deg.begin(), deg.end());
        long long val = 1, ans = 0;
        for(long long d : deg){
            ans += (val * d);
            val++;
        }
        return ans;
    }
};