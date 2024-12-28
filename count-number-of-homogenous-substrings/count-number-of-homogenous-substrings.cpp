class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size(), ans = 0, cnt = 0, mod = 1e9+7;
        char prev = ' ';
        for(int i=0; i<n; i++){
            if(prev==s[i]) cnt++;
            else cnt = 1;
            prev = s[i];
            ans = (ans+cnt)%mod;
        }
        return ans;
    }
};