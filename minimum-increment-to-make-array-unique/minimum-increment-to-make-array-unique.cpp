class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int mn = 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                int inc = nums[i-1]+1 - nums[i];
                mn += inc;
                nums[i] = nums[i-1]+1;
            }
        }
        return mn;
    }
};