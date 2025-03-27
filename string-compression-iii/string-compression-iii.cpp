class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;
        while(i < word.size()){
            int cnt = 0;
            char currChar = word[i];
            while(i < word.size() && cnt < 9 && word[i] == currChar){
                cnt++;
                i++;
            }
            comp += to_string(cnt) + currChar;
        }
        return comp;
    }
};