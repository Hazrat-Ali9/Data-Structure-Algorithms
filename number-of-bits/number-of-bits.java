public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int cnt = 0;
        while(n != 0){
            n = n & n-1;
            cnt++;
        }
        return cnt;
    }
}

// Number of bits java