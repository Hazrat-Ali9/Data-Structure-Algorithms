class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        // Traverse through the relative order array
        for (int i = 0; i < arr2.size(); i++) {
            // Traverse through the target array
            for (int j = 0; j < arr1.size(); j++) {
                // If element in target array matches with
                // relative order element
                if (arr1[j] == arr2[i]) {
                    // Add it to the result array
                    result.push_back(arr1[j]);
                    // Mark the element in target array as visited
                    arr1[j] = -1;
                }
            }
        }
        // Sort the remaining elements in the target array
        sort(arr1.begin(), arr1.end());
        // Add the remaining elements to the result array
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] != -1) {
                result.push_back(arr1[i]);
            }
        }
        return result;
    }
};