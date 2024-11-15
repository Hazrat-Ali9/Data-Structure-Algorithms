class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> arr;
        // for(int x : nums1) arr.push_back(x);
        // for(int x : nums2) arr.push_back(x);
        // sort(arr.begin(), arr.end());
        // if(arr.size()%2) return (double) arr[arr.size()/2];
        // else return (double)(arr[arr.size()/2]+arr[arr.size()/2 - 1])/2;
        int n = nums1.size(), m = nums2.size();
        vector<int> arr(n+m, 0);
        int i = 0, j = 0, k = -1;
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]) arr[++k] = nums1[i++];
            else arr[++k] = nums2[j++];
        }
        while(i < n) arr[++k] = nums1[i++];
        while(j < m) arr[++k] = nums2[j++];
        if(arr.size()%2) return (double) arr[arr.size()/2];
        else return (double)(arr[arr.size()/2]+arr[arr.size()/2 - 1])/2;
    }
};

// Error