class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        if(s == goal){
            vector<int> freq(26, 0);
            for(auto x : s){
                freq[x - 'a']++;
                if(freq[x-'a'] == 2) return true;
            }
            return false;
        }
        int fIndex = -1, sIndex = -1;
        for(int i=0; i<s.size(); i++){
            if(s[i] != goal[i]){
                if(fIndex == -1) fIndex = i;
                else if(sIndex == -1) sIndex = i;
                else return false;
            }
        }
        if(sIndex == -1) return false;
        return s[fIndex] == goal[sIndex] && s[sIndex] == goal[fIndex];
    }
};