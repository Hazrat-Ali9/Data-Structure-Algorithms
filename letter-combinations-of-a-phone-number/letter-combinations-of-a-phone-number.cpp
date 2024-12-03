class Solution {
public:
    vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        combi(0, "", digits);
        return ans;
    }
    void combi(int i, string curr, string digits){
        if(i == digits.size()){
            ans.push_back(curr);
            return;
        }
        for(auto x : mp[digits[i]-'2']){
            curr.push_back(x);
            combi(i+1, curr, digits);
            curr.pop_back();
        }
    }
};