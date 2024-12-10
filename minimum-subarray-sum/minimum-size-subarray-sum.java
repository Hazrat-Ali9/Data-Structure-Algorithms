class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int l=0, sum=0, ans=Integer.MAX_VALUE;
        for(int r=0; r<nums.length; r++){
            sum += nums[r];
            while(sum >= target){
                ans = Math.min(ans, r-l+1);
                sum -= nums[l++];
            }
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}