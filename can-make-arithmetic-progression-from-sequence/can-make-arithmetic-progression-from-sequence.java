class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int mn = Arrays.stream(arr).min().getAsInt();
        int mx = Arrays.stream(arr).max().getAsInt();
        int n = arr.length;
        if(mx - mn == 0) return true;
        if((mx - mn) % (n-1) != 0) return false;
        int diff = (mx - mn) / (n-1);
        Set<Integer> s = new HashSet<>();
        for(int i=0; i<n; i++){
            if((arr[i] - mn) % diff != 0) return false;
            s.add(arr[i]);
        }
        return s.size() == n;
    }
}