class Solution {
    public long minimumReplacement(int[] nums) {
        long ans = 0;
        int n = nums.length;
        for(int i=n-2; i>=0; i--){
            if(nums[i] <= nums[i+1]) continue;
            long numElement = (long)(nums[i]+nums[i+1]-1)/(long)(nums[i+1]);
            ans += numElement-1;
            nums[i] = nums[i]/(int)numElement;
        }
        return ans;
    }
}