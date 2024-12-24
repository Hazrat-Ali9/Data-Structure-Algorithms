class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int cnt1=0, cnt2=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>=nums[i-1]) cnt1++;
            if(nums[i]<=nums[i-1]) cnt2++;
        }
        return cnt1==nums.size()-1 || cnt2==nums.size()-1;
    }
};