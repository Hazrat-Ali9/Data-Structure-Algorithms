class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        for(int i=0; i<s.size()-1; i++){
            int cnt = 0;
            for(int j=0; j<=i; j++){
                if(s[j] == '0') cnt++;
            }
            for(int j=i+1; j<s.size(); j++){
                if(s[j] == '1') cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};