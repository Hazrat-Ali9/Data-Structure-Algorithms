class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size(), mxDigitIdx = -1, swapIdx1 = -1, swapIdx2 = -1;
        for(int i=n-1; i>=0; i--){
            if(mxDigitIdx==-1 || s[i] > s[mxDigitIdx]) mxDigitIdx = i;
            else if(s[i] < s[mxDigitIdx]){
                swapIdx1 = i;
                swapIdx2 = mxDigitIdx;
            }
        }
        if(swapIdx1 != -1 && swapIdx2 != -1) swap(s[swapIdx1], s[swapIdx2]);
        return stoi(s);
    }
};