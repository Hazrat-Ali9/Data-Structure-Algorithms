class Solution {
    public int longestSubarray(int[] nums, int limit) {
        int n = nums.length, i=0, j=0, mxLen = 0;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        while(j < n){
            mp.put(nums[j], mp.getOrDefault(nums[j], 0)+1);
            int diff = mp.lastKey() - mp.firstKey();
            while(diff > limit){
                int cnt = mp.get(nums[i]);
                if(cnt == 1) mp.remove(nums[i]);
                else mp.put(nums[i], cnt-1);
                diff = mp.lastKey()-mp.firstKey();
                i++;
            }
            mxLen = Math.max(mxLen, j-i+1);
            j++;
        }
        return mxLen;
    }
}