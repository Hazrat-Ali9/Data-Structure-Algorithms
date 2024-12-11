class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s == t) return true;
        if(s.size() != t.size()) return false;
        vector<int> v(26, 0);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(v[i]) return false;
        }
        return true;
    }
};