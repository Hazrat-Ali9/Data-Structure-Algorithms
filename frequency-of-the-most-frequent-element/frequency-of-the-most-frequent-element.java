class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0, ans = 0;
        long curr = 0;
        for(int r=0; r<nums.length; r++){
            long target = nums[r];
            curr += target;
            while((r-l+1)*target-curr > k) curr -= nums[l++];
            ans = Math.max(ans, r-l+1);
        }
        return ans;
    }
}