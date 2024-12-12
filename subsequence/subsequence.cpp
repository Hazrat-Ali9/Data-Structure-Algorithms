class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        for(int j=0; j<t.size(); j++){
            if(s[i]==t[j]) i++;
        }
        return i==s.size() ? true : false;
    }
};