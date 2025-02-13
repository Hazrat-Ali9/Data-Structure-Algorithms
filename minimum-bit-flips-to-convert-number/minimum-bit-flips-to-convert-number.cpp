class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start==0 && goal==0) return 0;
        int flip = (start&1) != (goal&1);
        return flip+minBitFlips(start>>1, goal>>1);
    }
};