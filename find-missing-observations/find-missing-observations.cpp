class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sum = sum + rolls[i];
        }
        // Find the remaining sum.
        int remainingSum = mean * (n + rolls.size()) - sum;
        // Check if sum is valid or not.
        if (remainingSum > 6 * n or remainingSum < n) {
            return {};
        }
        int distributeMean = remainingSum / n;
        int mod = remainingSum % n;
        // Distribute the remaining mod elements in nElements array.
        vector<int> nElements(n, distributeMean);
        for (int i = 0; i < mod; i++) {
            nElements[i]++;
        }
        return nElements;
    }
};