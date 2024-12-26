class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer, Integer> dp = new HashMap<>();
        int ans = 1;
        for(int a : arr){
            int beforeA = dp.getOrDefault(a-difference, 0);
            dp.put(a, beforeA+1);
            ans = Math.max(ans, dp.get(a));
        }
        return ans;
    }
}