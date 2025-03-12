class Solution {
    public boolean validPartition(int[] nums) {
        Map<Integer, Boolean> dp = new HashMap<>();
        dp.put(-1, true);
        return f(nums.length-1, nums, dp);
    }
    boolean f(int i, int[] nums, Map<Integer, Boolean> dp){
        if(dp.containsKey(i)) return dp.get(i);
        boolean ans = false;
        if(i>0 && nums[i]==nums[i-1]) ans |= f(i-2, nums, dp);
        if(i>1 && nums[i]==nums[i-1] && nums[i-1]==nums[i-2]){
            ans |= f(i-3, nums, dp);
        }
        if(i>1 && nums[i]==nums[i-1]+1 && nums[i-1]==nums[i-2]+1){
            ans |= f(i-3, nums, dp);
        }
        dp.put(i, ans);
        return ans;
    }
}