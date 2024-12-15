class Solution {
public:
    int minSteps(int n) {
        int ans = 0, d = 2;
        while(n > 1){
            // d is prime factor, keep dividing
            // n by d untill is no longer divisible
            while(n%d == 0){
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};