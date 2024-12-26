class Solution {
    public int findSpecialInteger(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap();
        int target = arr.length/4;
        for(int x : arr){
            cnt.put(x, cnt.getOrDefault(x, 0)+1);
            if(cnt.get(x) > target) return x;
        }
        return -1;
    }
}