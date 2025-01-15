class Solution {
public:
    int largestVariance(string s) {
        vector<int> cnt(26, 0);
        for(char c : s) cnt[c-'a']++;
        int globalMax = 0;
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                // major and minor cannot be the same, and both must appear in s.
                if(i==j || cnt[i]==0 || cnt[j]==0) continue;
                // Find the maximum variance of major - minor. 
                char major = 'a' + i;
                char minor = 'a' + j;
                int majorCnt = 0, minorCnt = 0;
                // The remaining minor in the rest of s.
                int restMinor = cnt[j];
                for(char c : s){
                    if(c == major) majorCnt++;
                    if(c == minor){
                        minorCnt++;
                        restMinor--;
                    }
                    // Only update the variance (local_max) if there is at least one minor.
                    if(minorCnt > 0) globalMax = max(globalMax, majorCnt - minorCnt);
                    // We can discard the previous string if there is at least one remaining minor
                    if(majorCnt < minorCnt && restMinor > 0){
                        majorCnt = 0;
                        minorCnt = 0;
                    }
                }
            }
        }
        return globalMax;
    }
};