class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int lastSpaceIndex = -1;
        for(int i=0; i<s.size(); i++){
            if(i==s.size()-1 || s[i]==' '){
                int j = (i == s.size()-1) ? i : i-1;
                for(; j > lastSpaceIndex; j--){
                    ans += s[j];
                }
                if(i != s.size()-1) ans += ' ';
                lastSpaceIndex = i;
            }
        }
        return ans;
    }
};