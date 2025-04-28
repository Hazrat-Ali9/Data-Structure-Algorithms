class Solution {
public:
    long long minimumSteps(string s) {
        int blackBallCount = 0;
        long long swaps = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                // Swap with all black balls to its left
                swaps += (long long) blackBallCount;
            }
            else{
                // Increment the count
                blackBallCount++;
            }
        }
        return swaps;
    }
};