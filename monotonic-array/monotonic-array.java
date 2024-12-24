class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean increasing = true, decreasing = true;
        for(int i=1; i<nums.length; i++){
            if(nums[i] > nums[i-1]) decreasing = false;
            else if(nums[i] < nums[i-1]) increasing = false;
            if(increasing==false && decreasing==false) return false;
        }
        return true;
    }
}