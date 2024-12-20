class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0, mnAddRequired = 0;
        for(char c : s){
            if(c == '(') openBrackets++;
            else{
                // If open bracket exists, match it with the closing one
                // If not, we need to add a open bracket.
                openBrackets > 0 ? openBrackets-- : mnAddRequired++;
            }
        }
        return mnAddRequired + openBrackets;
    }
};