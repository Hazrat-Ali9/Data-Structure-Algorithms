class TrieNode{
    public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
};
class Solution {
public:
    TrieNode* buildTrie(vector<string> &dic){
        auto root = new TrieNode();
        for(auto word : dic){
            auto node = root;
            for(auto c : word){
                if(node->children.find(c) == node->children.end()){
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isWord = true;
        }
        return root;
    }
    TrieNode *root;
    unordered_map<int, int> dp;
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        root = buildTrie(dictionary);
        return f(0, n, s);
    }
    int f(int start, int n, string &s){
        if(start == n) return 0;
        if(dp.count(start)) return dp[start];
        int ans = f(start+1, n, s) + 1;
        TrieNode* node = root;
        for(int r=start; r<n; r++){
            char c = s[r];
            if(node->children.find(c) == node->children.end()) break;
            node = node->children[c];
            if(node->isWord){
                ans = min(ans, f(r+1, n, s));
            }
        }
        return dp[start] = ans;
    }
};