class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a set to store the allowed characters
        unordered_set<char> allowedChars;
        // Populate the set with characters from the 'allowed' string
        for (int i = 0; i < allowed.length(); i++) allowedChars.insert(allowed[i]);
        int consistentCount = 0;
        // Iterate through each word in the 'words' array
        for (string& word : words) {
            bool isConsistent = true;
            // Check each character of the current word
            for (int i = 0; i < word.length(); i++) {
                char currentChar = word[i];
                // If the character is not in the allowedChars set, mark as
                // inconsistent and break
                if (allowedChars.find(currentChar) == allowedChars.end()) {
                    isConsistent = false;
                    break;
                }
            }
            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }
        // Return the total count of consistent strings
        return consistentCount;
    }
};