class Solution {
    public long minEnd(int n, int x) {
        long ans = x;
        while(--n > 0) ans = (ans + 1) | x;
        return ans;
    }
}