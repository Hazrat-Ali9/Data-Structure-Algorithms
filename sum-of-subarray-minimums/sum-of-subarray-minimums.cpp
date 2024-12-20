class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        long ans = 0;
        int mod = 1e9+7;
        for(int i=0; i<=arr.size(); i++){
            while(!s.empty() && (i==arr.size() || arr[s.top()] >= arr[i])){
                int mid = s.top(); s.pop();
                int l = s.empty() ? -1 : s.top();
                int r = i;
                long cntIndex = (mid-l) * (r-mid) % mod;
                ans += (arr[mid] * cntIndex) % mod;
                ans %= mod;
            }
            s.push(i);
        }
        return ans;
    }
};