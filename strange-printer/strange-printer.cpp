class Solution {
public:
    int strangePrinter(string s) {
        // Preprocess the string to remove consecutive duplicate characters
        s = removeDuplicates(s);
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n, -1));
        return f(0, n-1, s, dp);
    }
    int f(int start, int end, string &s, vector<vector<int>>&dp){
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        // Initialize with worst case: print each character separately
        int minTurns = 1 + f(start + 1, end, s, dp);
        // Try to optimize by finding matching characters
        for(int k = start+1; k<=end; k++){
            if(s[k] == s[start]){
                // If match found, try splitting the problem
                int turnsWithMatch = f(start, k - 1, s, dp) + f(k + 1, end, s, dp);
                minTurns = min(minTurns, turnsWithMatch);
            }
        }
        // Memoize and return the result
        return dp[start][end] = minTurns;
    }
    string removeDuplicates(string& s) {
        string uniqueChars;
        int i = 0;
        while(i < s.length()){
            char currentChar = s[i];
            uniqueChars += currentChar;
            // Skip all consecutive occurrences of the current character
            while (i < s.length() && s[i] == currentChar) {
                i++;
            }
        }
        return uniqueChars;
    }
};