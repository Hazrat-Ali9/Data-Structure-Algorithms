class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int ans = n;
        HashSet<Integer> st = new HashSet<>();
        for(int x : nums) st.add(x);
        int[] arr = new int[st.size()];
        int in = 0;
        for(int x : st) arr[in++] = x;
        Arrays.sort(arr);
        int j = 0;
        for(int i=0; i<arr.length; i++){
            while(j<arr.length && arr[j] < arr[i]+n) j++;
            int cnt  = j-i;
            ans = Math.min(ans, n-cnt);
        }
        return ans;
    }
}