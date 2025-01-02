class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        set<int> unique(nums.begin(), nums.end());
        vector<int> arr;
        for(int x : unique) arr.push_back(x);
        for(int i=0; i<arr.size(); i++){
            int l = arr[i];
            int r = l+n-1;
            int j = upper_bound(arr.begin(), arr.end(), r) - arr.begin();
            int cnt = j - i;
            ans = min(ans, n-cnt);
        }
        return ans;
    }
};