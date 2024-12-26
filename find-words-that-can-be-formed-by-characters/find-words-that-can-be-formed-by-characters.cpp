class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp(26, 0);
        for(char c : chars) mp[c-'a']++;
        int ans = 0;
        for(string s : words){
            vector<int> v(26, 0);
            for(char c : s) v[c-'a']++;
            bool isValid = true;
            for(char c : s){
                if(mp[c-'a'] < v[c-'a']){
                    isValid = false;
                    break;
                }
            }
            ans += isValid ? s.size() : 0;
        }
        return ans;
    }
};