class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        while(--n) ans = (ans + 1) | x;
        return ans;
    }
};