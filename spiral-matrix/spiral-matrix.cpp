class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> traversed;
        for(int step=1, d=0; traversed.size()<rows*cols;){
            //direction = 0 -> East, 1 -> South, 2->West, 3->North
            for(int i=0; i<2; i++){
                for(int j=0; j<step; j++){
                    if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart<cols){
                        traversed.push_back({rStart, cStart});
                    }
                    rStart += dir[d][0];
                    cStart += dir[d][1];
                }
                d = (d + 1) % 4;
            }
            ++step;
        }
        return traversed;
    }
};