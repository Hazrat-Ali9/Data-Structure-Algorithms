class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAlt = 0, mxAlt = 0;
        for(int x : gain){
            currAlt += x;
            mxAlt = max(mxAlt, currAlt);
        }
        return mxAlt;
    }
};