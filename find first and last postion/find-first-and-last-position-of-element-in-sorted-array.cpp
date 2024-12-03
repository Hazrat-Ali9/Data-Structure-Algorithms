class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, f=-1, s=-1;
        while(l <= r){
            int m = (l+r)/2;
            if(nums[m] == target){
                f = m;
                r = m-1;
            }
            else if(nums[m] < target) l = m+1;
            else r = m-1;
        }
        l = 0, r = nums.size()-1;
        while(l <= r){
            int m = (l+r)/2;
            if(nums[m] == target){
                s = m;
                l = m+1;
            }
            else if(nums[m] < target) l = m+1;
            else r = m-1;
        }
        return {f, s};
    }
};