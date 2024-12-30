class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<n; i++) pq.push({nums[i], i});
        int ans = 0, mod = 1e9+7;
        for(int i=1; i<=right; i++){
            auto p = pq.top();pq.pop();
            if(i>=left) ans = (ans+p.first)%mod;
            if(p.second < n-1){
                p.first += nums[++p.second];
                pq.push(p);
            }
        }
        return ans;
    }
};