class Solution {
    public int maxProductDifference(int[] nums) {
        int big = 0, sBig = 0;
        int small = Integer.MAX_VALUE, sSmall = Integer.MAX_VALUE;
        for(int x : nums){
            if(x > big){
                sBig = big;
                big = x;
            }
            else sBig = Math.max(sBig, x);
            if(x < small){
                sSmall = small;
                small = x;
            }
            else sSmall = Math.min(sSmall, x);
        }
        return big*sBig - small*sSmall;
    }
}