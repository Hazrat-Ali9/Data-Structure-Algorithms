class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        int ans = 0;
        bool hasOddFreq = false;
        for(auto x : freq){
            int cnt = x.second;
            if(cnt%2 == 0) ans += cnt;
            else{
                ans += cnt-1;
                hasOddFreq = true;
            }
        }
        if(hasOddFreq) ans++;
        return ans;
    }
};