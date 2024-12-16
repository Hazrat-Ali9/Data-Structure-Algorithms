class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l=0, r=nums[n-1] - nums[0];
        while(l < r){
            int m = (l+r)/2;
            int cnt = countPairWithDistance(nums, m);
            if(cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
    int countPairWithDistance(vector<int>&nums, int mxDist){
        int cnt = 0, n = nums.size(), l = 0;
        for(int r=0; r<n; r++){
            while(nums[r]-nums[l] > mxDist) l++;
            cnt += r-l;
        }
        return cnt;
    }
};