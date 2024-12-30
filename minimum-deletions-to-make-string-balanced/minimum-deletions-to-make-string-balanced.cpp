class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), mnDel = 0, bCnt=0;
        for(int i=0; i<n; i++){
            if(s[i] == 'b') bCnt++;
            else mnDel = min(mnDel+1, bCnt);
        }
        return mnDel;
    }
};