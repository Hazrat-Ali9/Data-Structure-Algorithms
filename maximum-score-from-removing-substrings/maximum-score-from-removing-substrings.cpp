class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = highPriorityPair == "ab" ? "ba" : "ab";

        // First pass: remove high priority pair
        string stringAfterFirstPass = removeSubstring(s, highPriorityPair);
        int removedPairsCount =
            (s.length() - stringAfterFirstPass.length()) / 2;

        // Calculate score from first pass
        totalScore += removedPairsCount * max(x, y);

        // Second pass: remove low priority pair
        string stringAfterSecondPass =
            removeSubstring(stringAfterFirstPass, lowPriorityPair);
        removedPairsCount =
            (stringAfterFirstPass.length() - stringAfterSecondPass.length()) /
            2;

        // Calculate score from second pass
        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

private:
    string removeSubstring(const string& input, const string& targetPair) {
        stack<char> charStack;

        // Iterate through each character in the input string
        for (char currentChar : input) {
            // Check if current character forms the target pair with the top of
            // the stack
            if (currentChar == targetPair[1] && !charStack.empty() &&
                charStack.top() == targetPair[0]) {
                charStack
                    .pop();  // Remove the matching character from the stack
            } else {
                charStack.push(currentChar);
            }
        }

        // Reconstruct the remaining string after removing target pairs
        string remainingChars;
        while (!charStack.empty()) {
            remainingChars += charStack.top();
            charStack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());
        return remainingChars;
    }
};