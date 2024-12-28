class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> folderStack;
        for(auto x : logs){
            if(x == "../"){
                if(!folderStack.empty()) folderStack.pop();
            }
            else if(x != "./") folderStack.push(x);
        }
        return folderStack.size();
    }
};