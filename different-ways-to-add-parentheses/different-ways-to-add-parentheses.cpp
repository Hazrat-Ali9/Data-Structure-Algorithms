class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<vector<vector<int>>> dp(expression.size(), vector<vector<int>>(expression.size()));
        return computeAns(expression, dp, 0, expression.size()-1);
    }
    vector<int> computeAns(string &expression, vector<vector<vector<int>>>&dp, int start, int end){
        if(!dp[start][end].empty()) return dp[start][end];
        vector<int> ans;
        if(start == end){
            ans.push_back(expression[start]-'0');
            return ans;
        }
        if(end-start==1 && isdigit(expression[start])){
            int tens = expression[start]-'0';
            int ones = expression[end]-'0';
            ans.push_back(10*tens+ones);
            return ans;
        }
        for(int i=start; i<=end; i++){
            char currChar = expression[i];
            if(isdigit(currChar)) continue;
            vector<int> leftAns = computeAns(expression, dp, start, i-1);
            vector<int> rightAns = computeAns(expression, dp, i+1, end);
            for(int leftValue :leftAns){
                for(int rightValue : rightAns){
                    switch(currChar){
                        case '+':
                            ans.push_back(leftValue+rightValue);
                            break;
                        case '-':
                            ans.push_back(leftValue-rightValue);
                            break;
                        case '*':
                            ans.push_back(leftValue*rightValue);
                            break;
                    }
                }
            }
        }
        dp[start][end] = ans;
        return ans;
    }
};