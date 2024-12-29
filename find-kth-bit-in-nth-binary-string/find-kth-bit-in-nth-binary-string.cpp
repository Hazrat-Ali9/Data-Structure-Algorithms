class Solution {
public:
    char findKthBit(int n, int k) {
        int invertCount = 0;
        int len = (1 << n) - 1;  // Length of Sn is 2^n - 1
        while (k > 1) {
            // If k is in the middle, return based on inversion count
            if (k == len / 2 + 1) {
                return invertCount % 2 == 0 ? '1' : '0';
            }
            // If k is in the second half, invert and mirror
            if (k > len / 2) {
                k = len + 1 - k;  // Mirror position
                invertCount++;    // Increment inversion count
            }
            len /= 2;  // Reduce length for next iteration
        }
        // For the first position, return based on inversion count
        return invertCount % 2 == 0 ? '0' : '1';
    }
};