class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int mnSwaps = INT_MAX, totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int onesCnt = nums[0], end = 0;
        for(int start=0; start<nums.size(); start++){
            if(start != 0) onesCnt -= nums[start-1];
            while(end-start+1 < totalOnes){
                end++;
                onesCnt += nums[end%nums.size()];
            }
            mnSwaps = min(mnSwaps, totalOnes-onesCnt);
        }
        return mnSwaps;
    }
};