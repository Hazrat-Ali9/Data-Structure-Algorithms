class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0], biggest = arrays[0].back(), mxDis = 0;
        for(int i=1; i<arrays.size(); i++){
            mxDis = max(mxDis, abs(arrays[i].back() - smallest));
            mxDis = max(mxDis, abs(biggest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }
        return mxDis;
    }
};