class Solution {
public:
    const int hash_multiplier = 60001;
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obstacleSet;
        for(auto &obstacle : obstacles) obstacleSet.insert(hashCordinate(obstacle[0], obstacle[1]));
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> currPos = {0, 0};
        int mxDist = 0, currDirec = 0;  // 0 : North, 1 : East, 2 : South, 3 : West
        for(int command : commands){
            if(command == -1){
                //Turn Right
                currDirec = (currDirec + 1) % 4;
                continue;
            }
            if(command == -2){
                //Turn Left
                currDirec = (currDirec + 3) % 4;
                continue;
            }
            //Move Forward
            vector<int> direc = direction[currDirec];
            for(int step=0; step<command; step++){
                int nxtX = currPos[0] + direc[0];
                int nxtY = currPos[1] + direc[1];
                if(obstacleSet.contains(hashCordinate(nxtX, nxtY))) break;
                currPos[0] = nxtX;
                currPos[1] = nxtY;
            }
            mxDist = max(mxDist, currPos[0]*currPos[0] + currPos[1]*currPos[1]);
        }
        return mxDist;
    }
    int hashCordinate(int x, int y){
        return x + hash_multiplier*y;
    }
};