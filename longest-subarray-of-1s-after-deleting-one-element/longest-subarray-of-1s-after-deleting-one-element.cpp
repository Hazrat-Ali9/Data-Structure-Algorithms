class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt0 = 0, longestWindow = 0, start = 0;
        for(int i=0; i<nums.size(); i++){
            cnt0 += (nums[i]==0);
            while(cnt0 > 1){
                cnt0 -= (nums[start] == 0);
                start++;
            }
            longestWindow = max(longestWindow, i-start);
        }
        return longestWindow;
    }
};