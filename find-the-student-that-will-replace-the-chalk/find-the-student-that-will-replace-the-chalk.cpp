class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        for (int i = 0; i < chalk.size(); i++) {
            sum += chalk[i];
            if (sum > k) {
                break;
            }
        }
        // Find modulo of k with sum.
        k = k % sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k = k - chalk[i];
        }
        return 0;
    }
};