class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> commonCharCnt(26, 0), currentCharCnt(26, 0);
        for(char c : words[0]) commonCharCnt[c-'a']++;
        for(int i=1; i<words.size(); i++){
            fill(currentCharCnt.begin(), currentCharCnt.end(), 0);
            //Count char in the current word
            for(char c : words[i]) currentCharCnt[c-'a']++;
            //Update the common char count to keep the minimum counts
            for(int j=0; j<26; j++){
                commonCharCnt[j] = min(commonCharCnt[j], currentCharCnt[j]);
            }
        }
        vector<string> ans;
        //COllect the common char to keep the minimum counts
        for(int i=0; i<26; i++){
            for(int j=0; j<commonCharCnt[i]; j++) ans.push_back(string(1, i+'a'));
        }
        return ans;
    }
};