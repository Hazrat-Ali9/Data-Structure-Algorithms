class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixXOR = 0;
        vector<int> charMap(26, 0);
        charMap['a'-'a'] = 1;
        charMap['e'-'a'] = 2;
        charMap['i'-'a'] = 4;
        charMap['o'-'a'] = 8;
        charMap['u'-'a'] = 16;
        vector<int> mp(32, -1);
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            prefixXOR ^= charMap[s[i]-'a'];
            if(mp[prefixXOR] == -1 and prefixXOR != 0) mp[prefixXOR] = i;
            ans = max(ans, i-mp[prefixXOR]);
        }
        return ans;
    }
};