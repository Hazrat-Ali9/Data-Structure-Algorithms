class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        while(i<s.size() && j<t.length()){
            if(s[i]==t[j]) j++;
            i++;
        }
        return t.size()-j;
    }
};