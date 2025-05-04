class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        // Check pairs of characters (i, i+1) with step size 2
        for(int i=0; i<s.size(); i+=2){
            // If characters in current pair don't match, we need one change to make them equal
            if(s[i] != s[i+1]) cnt++;
        }
        return cnt;
    }
};