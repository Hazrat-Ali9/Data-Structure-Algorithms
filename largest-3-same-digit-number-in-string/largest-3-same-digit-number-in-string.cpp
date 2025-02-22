class Solution {
public:
    string largestGoodInteger(string num) {
        char mxDigit = ' ';
        for(int i=0; i<=num.size()-3; i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]) mxDigit = max(mxDigit, num[i]);
        }
        return mxDigit == ' ' ? "" : string(3, mxDigit);
    }
};