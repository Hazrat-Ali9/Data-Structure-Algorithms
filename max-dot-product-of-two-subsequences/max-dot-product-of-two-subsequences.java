class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int firstMax = Integer.MIN_VALUE, firstMin = Integer.MAX_VALUE;
        int secondMax= Integer.MIN_VALUE, secondMin = Integer.MAX_VALUE;
        for(int a : nums1){
            firstMax = Math.max(firstMax, a);
            firstMin = Math.min(firstMin, a);
        }
        for(int a : nums2){
            secondMax = Math.max(secondMax, a);
            secondMin = Math.min(secondMin, a);
        }
        if(firstMax<0 && secondMin>0) return firstMax*secondMin;
        if(secondMax<0 && firstMin>0) return secondMax*firstMin;
        int[][] dp = new int[nums1.length][nums2.length];
        for(int[] row : dp){
            Arrays.fill(row, 0);
        }
        return f(0, 0, nums1,nums2, dp);
    }
    int f(int i, int j, int[] nums1, int[] nums2, int[][] dp){
        if(i==nums1.length || j==nums2.length) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        int use = nums1[i]*nums2[j] + f(i+1, j+1, nums1, nums2, dp);
        dp[i][j] = Math.max(use, Math.max(f(i+1, j, nums1, nums2, dp), f(i, j+1, nums1, nums2, dp)));
        return dp[i][j];
    }
}