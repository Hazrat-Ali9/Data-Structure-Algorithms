class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        int mxCnt = 0;
        backtrack(0, 0, s, seen, mxCnt);
        return mxCnt;
    }
    void backtrack(int i, int cnt, string &s, unordered_set<string> &seen, int &mxCnt){
        if(cnt + (s.size()-i) <= mxCnt) return;
        if(i == s.size()){
            mxCnt = max(mxCnt, cnt);
            return;
        }
        for(int j=i+1; j<=s.size(); j++){
            string subS = s.substr(i, j-i);
            if(seen.find(subS) == seen.end()){
                seen.insert(subS);
                backtrack(j, cnt+1, s, seen, mxCnt);
                seen.erase(subS);
            }
        }
    }
};