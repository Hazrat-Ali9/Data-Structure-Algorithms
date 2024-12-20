//MergeSort,  T.C -> O(nlogn),  S.C -> O(n)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
    void mergeSort(vector<int>&nums, int start, int end){
        if(start < end){
            int mid = start + (end - start)/2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid+1, end);
            merge(nums, start, mid, end);
        }
    }
    // sort an array
    void merge(vector<int> &nums, int low, int mid, int high){
        if(low >= high) return;
        int l = low, r = mid+1, k = 0, sz = high - low + 1;
        vector<int> sorted(sz, 0);
        while(l <= mid && r <= high) sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        while(l <= mid) sorted[k++] = nums[l++];
        while(r <= high) sorted[k++] = nums[r++];
        for(k=0; k<sz; k++) nums[k+low] = sorted[k];
    }
};