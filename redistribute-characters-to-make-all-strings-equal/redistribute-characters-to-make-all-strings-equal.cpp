class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26, 0);
        for(string word : words){
            for(char c : word) cnt[c-'a']++;
        }
        int n = words.size();
        for(int val : cnt){
            if(val % n != 0) return false;
        }
        return true;
    }
};