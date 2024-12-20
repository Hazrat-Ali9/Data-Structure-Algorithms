class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream str1(s1), str2(s2);
        unordered_map<string, int> cnt;
        string word;
        while(str1 >> word) cnt[word]++;
        while(str2 >> word) cnt[word]++;
        vector<string> ans;
        for(auto x : cnt){
            if(x.second == 1) ans.push_back(x.first);
        }
        return ans;
    }
};