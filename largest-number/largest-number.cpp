class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Priority queue to order numbers using the custom comparison
        // function
        priority_queue<string, vector<string>, decltype(&Solution::compare)>
            maxHeap(&Solution::compare);

        int totalLength = 0;

        // Convert integers to strings and push them into the priority queue
        for (const int num : nums) {
            string strNum = to_string(num);
            totalLength += strNum.size();
            maxHeap.push(strNum);
        }

        // Build the result string from the priority queue
        string result;
        result.reserve(totalLength);  // Reserve space for efficiency
        while (!maxHeap.empty()) {
            result += maxHeap.top();
            maxHeap.pop();
        }

        // Handle edge case where the result might be "000...0"
        if (result.empty() || result[0] == '0') {
            return "0";
        }

        return result;
    }

private:
    // Private helper function to compare two strings
    static bool compare(const string& first, const string& second) {
        return (first + second) < (second + first);
    }
};