class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0, mx = nums.back();
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] != mx){
                mx = nums[i];
                cnt += nums.size()-i-1;
            }
        }
        return cnt;
    }
};