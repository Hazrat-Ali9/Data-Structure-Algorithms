class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size(), m = word2.size();
        int i=0, j=0, x = 0, y = 0;
        while(i<n && j<m){
            if(word1[i][x++] != word2[j][y++]) return false;
            if(x == word1[i].size()){
                i++;
                x = 0;
            }
            if(y == word2[j].size()){
                j++;
                y = 0;
            }
        }
        return i==n && j==m;
    }
};