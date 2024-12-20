class Solution {
    public int[] sortArray(int[] nums) {
        mergeSort(nums, 0, nums.length-1);
        return nums;
    }
    void mergeSort(int[] nums, int l, int r){
        if(l < r){
            int m = (l+r)/2;
            mergeSort(nums, l, m);
            mergeSort(nums, m+1, r);
            merge(nums, l, m, r);
        }
    }
    void merge(int[] nums, int l, int m, int r){
        if(l >= r) return;
        int s = l, e = m+1, n = r-l+1, k=0;
        int[] sortedArray = new int[n];
        while(s<=m && e<=r) sortedArray[k++] = nums[s]<nums[e] ? nums[s++] : nums[e++];
        while(s <= m) sortedArray[k++] = nums[s++];
        while(e <= r) sortedArray[k++] = nums[e++];
        for(k=0; k<n; k++) nums[l+k] = sortedArray[k];
    }
}