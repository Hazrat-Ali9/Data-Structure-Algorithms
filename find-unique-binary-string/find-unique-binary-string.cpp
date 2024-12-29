class Solution {
public:
    set<string> st;
    int n;
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for(string x : nums) st.insert(x);
        return generate("");
    }
    string generate(string curr){
        if(curr.size() == n){
            if(st.find(curr) == st.end()) return curr;
            return "";
        }
        string addZero = generate(curr+"0");
        if(addZero.size() > 0) return addZero;
        return generate(curr+"1");
    }
};