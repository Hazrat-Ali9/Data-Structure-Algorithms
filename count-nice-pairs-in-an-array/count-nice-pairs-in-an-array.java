class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> arr;
        for(int i=0; i<nums.size(); i++) arr.push_back(nums[i]-rev(nums[i]));
        unordered_map<int, int> mp;
        int ans = 0, mod = 1e9+7;
        for(int x : arr){
            ans = (ans + mp[x]) % mod;
            mp[x]++;
        }
        return ans;
    }
    int rev(int num){
        int res = 0;
        while(num > 0){
            res = res * 10 + num%10;
            num /= 10;
        }
        return res;
    }
};