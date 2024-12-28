class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> ans = new ArrayList();
        for(int i=0; i<l.length; i++){
            int[] arr = new int[r[i]-l[i]+1];
            for(int j=0; j<arr.length; j++) arr[j] = nums[l[i]+j];
            ans.add(check(arr));
        }
        return ans;
    }
    Boolean check(int[] arr){
        int mn = Integer.MAX_VALUE, mx = Integer.MIN_VALUE;
        Set<Integer> s = new HashSet();
        for(int x : arr){
            mn = Math.min(mn, x);
            mx = Math.max(mx, x);
            s.add(x);
        }
        if((mx-mn) % (arr.length-1) != 0) return false;
        int diff = (mx-mn)/(arr.length-1);
        int curr = mn + diff;
        while(curr < mx){
            if(!s.contains(curr)) return false;
            curr += diff;
        }
        return true;
    }
}