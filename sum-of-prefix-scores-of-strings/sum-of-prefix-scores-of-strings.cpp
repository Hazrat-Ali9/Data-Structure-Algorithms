struct TrieNode{
    TrieNode *next[26] = {};
    int cnt = 0;
};
class Solution {
public:
    TrieNode root;
    void insert(string word){
        auto node = &root;
        for(char c : word){
            //If new prefix xreate a new trie
            if(!node->next[c-'a']) node->next[c-'a'] = new TrieNode();
            node->next[c-'a']->cnt++;
            node = node->next[c-'a'];
        }
    }
    int count(string s){
        auto node = &root;
        int ans = 0;
        //ans would store the total sum of counts
        for(char c : s){
            ans += node->next[c-'a']->cnt;
            node = node->next[c-'a'];
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        for(int i=0; i<n; i++) insert(words[i]);
        vector<int> scores(n, 0);
        for(int i=0; i<n; i++){
            //Get the count of all prefixes of give string
            scores[i] = count(words[i]);
        }
        return scores;
    }
};