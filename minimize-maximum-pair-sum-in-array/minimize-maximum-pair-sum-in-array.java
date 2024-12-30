class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, n = nums.length;
        for(int i=0; i<n/2; i++) ans = Math.max(ans, nums[i]+nums[n-1-i]);
        return ans;
    }
}