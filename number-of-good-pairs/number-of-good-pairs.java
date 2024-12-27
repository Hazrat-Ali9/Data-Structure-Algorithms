class Solution {
    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int x : nums) mp.put(x, mp.getOrDefault(x, 0)+1);
        int cnt = 0;
        for(int a : mp.values()){
            if(a > 1) cnt += (a*(a-1))/2;
        }
        return cnt;
    }
}