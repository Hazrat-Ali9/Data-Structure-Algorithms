class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParenthesesIndices;
        string ans;
        for(char c : s){
            if(c == '('){
                openParenthesesIndices.push(ans.length());
            }
            else if(c == ')'){
                int start = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                reverse(ans.begin()+start, ans.end());
            }
            else ans += c;
        }
        return ans;
    }
};