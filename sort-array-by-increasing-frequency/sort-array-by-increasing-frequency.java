class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for(int num : nums) freq.put(num, freq.getOrDefault(num, 0)+1);
        Integer[] numsObj = new Integer[nums.length];
        for(int i=0; i<nums.length; i++) numsObj[i] = nums[i];
        Arrays.sort(numsObj, (a, b)->{
            if(freq.get(a).equals(freq.get(b))) return Integer.compare(b, a);
            return Integer.compare(freq.get(a), freq.get(b));
        });
        for(int i=0; i<nums.length; i++) nums[i] = numsObj[i];
        return nums;
    }
}