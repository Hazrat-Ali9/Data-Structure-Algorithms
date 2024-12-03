class Solution {
    public void sortColors(int[] nums) {
        int l=0, r =nums.length-1, i=0;
        while(i <= r){
            if(nums[i] == 0){
                int temp = nums[i];
                nums[i++] = nums[l];
                nums[l++] = temp;
            }
            else if(nums[i] == 2){
                int temp = nums[i];
                nums[i] = nums[r];
                nums[r--] = temp;
            }
            else i++;
        }
    }
}