class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Dictionary to maintain frequency count for arr
        unordered_map<int, int> arrFreq;
        for (int num : arr) {
            arrFreq[num]++;
        }
        // Dictionary to maintain frequency count for target
        unordered_map<int, int> targetFreq;
        for (int num : target) {
            targetFreq[num]++;
        }
        // Number of distinct elements of the 2 arrays are not equal
        if (arrFreq.size() != targetFreq.size()) {
            return false;
        }
        for (auto it : arrFreq) {
            // Frequency for num differs
            if (targetFreq[it.first] != it.second) {
                return false;
            }
        }
        return true;
    }
};