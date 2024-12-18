class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        s1 = sortString(s1);
        for(int i=0; i<=s2.length()-s1.length(); i++){
            if(s1 == sortString(s2.substr(i, s1.length()))){
                return true;
            }
        }
        return false;
    }
    string sortString(string s){
        sort(s.begin(), s.end());
        return s;
    }
};