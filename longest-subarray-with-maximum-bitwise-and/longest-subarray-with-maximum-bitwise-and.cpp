class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mxVal = 0, ans = 0, currStreak = 0;
        for(int x : nums){
            if(mxVal < x){
                mxVal = x;
                ans = currStreak = 0;
            }
            if(mxVal == x) currStreak++;
            else currStreak = 0;
            ans = max(ans, currStreak);
        }
        return ans;
    }
};