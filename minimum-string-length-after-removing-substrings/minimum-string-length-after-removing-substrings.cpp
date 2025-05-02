class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char c : s){
            if(st.empty()){
                st.push(c);
                continue;
            }
            if(c=='B' && st.top()=='A') st.pop();
            else if(c=='D' && st.top()=='C') st.pop();
            else st.push(c);
        }
        return st.size();
    }
};