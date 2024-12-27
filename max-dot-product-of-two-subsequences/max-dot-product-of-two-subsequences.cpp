class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = *max_element(nums1.begin(), nums1.end());
        int firstMin = *min_element(nums1.begin(), nums1.end());
        int secondMax = *max_element(nums2.begin(), nums2.end());
        int secondMin = *min_element(nums2.begin(), nums2.end());
        if(firstMax<0 && secondMin>0) return firstMax*secondMin;
        if(secondMax<0 && firstMin>0) return secondMax * firstMin;
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        return f(0, 0, nums1, nums2, dp);
    }
    int f(int i, int j, vector<int>&nums1, vector<int>&nums2, vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size()) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        int use = nums1[i]*nums2[j] + f(i+1, j+1, nums1, nums2, dp);
        dp[i][j] = max(use, max(f(i+1, j, nums1, nums2, dp), f(i, j+1, nums1, nums2, dp)));
        return dp[i][j];
    }
};