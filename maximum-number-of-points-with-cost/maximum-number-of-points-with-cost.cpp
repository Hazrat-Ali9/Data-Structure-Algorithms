class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long long> prevRow(m), currRow(m);
        for(auto row : points){
            long long runningMax = 0;
            //Left-Right pass
            for(int i=0; i<m; i++){
                runningMax = max(runningMax-1, prevRow[i]);
                currRow[i] = runningMax;
            }
            runningMax = 0;
            //Right-Left pass
            for(int i=m-1; i>=0; i--){
                runningMax = max(runningMax-1, prevRow[i]);
                currRow[i] = max(currRow[i], runningMax) + row[i];
            }
            //Update prevRow for the next iteration
            prevRow = currRow;
        }
        long long mxPoints = 0;
        for(int i=0; i<m; i++) mxPoints = max(mxPoints, prevRow[i]);
        return mxPoints;
    }
};