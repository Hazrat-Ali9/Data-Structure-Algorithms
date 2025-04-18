class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto &x : nums) pq.push(x);
        long long int ans = 0;
        while(k--){
            int mxElement = pq.top(); pq.pop();
            ans += mxElement;
            pq.push(ceil(mxElement/3.0));
        }
        return ans;
    }
};