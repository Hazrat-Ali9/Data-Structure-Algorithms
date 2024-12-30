class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int num : nums) sum += num;
        int len = -1, currSum = 0;
        for(int l=0, r=0; r<nums.size(); r++){
            currSum += nums[r];
            while(l <= r && currSum>sum-x) currSum -= nums[l++];
            if(currSum == sum-x) len = max(len, r-l+1);
        }
        return len==-1 ? -1 : nums.size()-len;
    }
};