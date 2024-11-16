class Solution {
public:
    string longestPalindrome(string s) {
        for(int l=s.size(); l>0; l--){
            for(int i=0; i<=s.size()-l; i++){
                if(palind(i, i+l, s)) return s.substr(i, l);
            }
        }
        return "";
    }
    bool palind(int i, int j, string &s){
        int l = i, r = j-1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};