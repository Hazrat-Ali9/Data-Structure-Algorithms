class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        // Flatten factory positions according to their capacities
        vector<int> factoryPositions;
        for (auto& f : factory)
            for (int i = 0; i < f[1]; i++) factoryPositions.push_back(f[0]);
        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<vector<long long>> memo(robotCount, vector<long long>(factoryCount, -1));
        // Recursively calculate minimum total distance with memoization
        return calculateMinDistance(0, 0, robot, factoryPositions, memo);
    }
    long long calculateMinDistance(int robotIdx, int factoryIdx, vector<int>& robot, vector<int>& factoryPositions, vector<vector<long long>>& memo) {
        // All robots assigned
        if (robotIdx == robot.size()) return 0;
        // No factories left to assign
        if (factoryIdx == factoryPositions.size()) return 1e12;
        // Check memo
        if (memo[robotIdx][factoryIdx] != -1) return memo[robotIdx][factoryIdx];
        // Option 1: Assign current robot to current factory
        long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) + calculateMinDistance(robotIdx + 1, factoryIdx + 1, robot, factoryPositions, memo);
        // Option 2: Skip current factory for the current robot
        long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot,factoryPositions, memo);
        return memo[robotIdx][factoryIdx] = min(assign, skip);  // Take the minimum and store in memo
    }
};