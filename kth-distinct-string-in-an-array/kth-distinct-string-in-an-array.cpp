class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinctStrings;
        unordered_set<string> duplicateStrings;
        // First pass: Identify distinct and duplicate strings
        for (auto& str : arr) {
            // If the string is already in duplicateStrings, skip further
            // processing
            if (duplicateStrings.count(str)) {
                continue;
            }
            // If the string is in distinctStrings, it means we have seen it
            // before, so move it to duplicateStrings
            if (distinctStrings.count(str)) {
                distinctStrings.erase(str);
                duplicateStrings.insert(str);
            } else {
                distinctStrings.insert(str);
            }
        }
        // Second pass: Find the k-th distinct string
        for (auto& str : arr) {
            if (!duplicateStrings.count(str)) {
                // Decrement k for each distinct string encountered
                k--;
            }
            // When k reaches 0, we have found the k-th distinct string
            if (k == 0) {
                return str;
            }
        }
        return "";
    }
};