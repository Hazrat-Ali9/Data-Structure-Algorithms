class Solution {
    public int longestSubarray(int[] nums) {
        int cnt0 = 0, longestWin = 0, start = 0;
        for(int i=0; i<nums.length; i++){
            cnt0 += (nums[i]==0 ? 1 : 0);
            while(cnt0 > 1){
                cnt0 -= (nums[start]==0 ? 1 : 0);
                start++;
            }
            longestWin = Math.max(longestWin, i-start);
        }
        return longestWin;
    }
}