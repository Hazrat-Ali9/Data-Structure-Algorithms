class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adjList(n);
        vector<vector<int>> shortestPathMat(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++) shortestPathMat[i][i] = 0;
        for(auto edge : edges){
            int start = edge[0], end = edge[1], weight = edge[2];
            adjList[start].emplace_back(end, weight);
            adjList[end].emplace_back(start, weight);
        }
        for(int i=0; i<n; i++){
            dijkstra(n, adjList, shortestPathMat[i], i);
        }
        return getCityWithFewestReachable(n, shortestPathMat, distanceThreshold);
    }
    void dijkstra(int n, const vector<vector<pair<int, int>>>& adjList,
                  vector<int>& shortestPathDistances, int source) {
        // Priority queue to process nodes with the smallest distance first
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            priorityQueue;
        priorityQueue.emplace(0, source);
        fill(shortestPathDistances.begin(), shortestPathDistances.end(),
             INT_MAX);
        shortestPathDistances[source] = 0;  // Distance to source itself is zero

        // Process nodes in priority order
        while (!priorityQueue.empty()) {
            auto [currentDistance, currentCity] = priorityQueue.top();
            priorityQueue.pop();
            if (currentDistance > shortestPathDistances[currentCity]) {
                continue;
            }

            // Update distances to neighboring cities
            for (const auto& [neighborCity, edgeWeight] :
                 adjList[currentCity]) {
                if (shortestPathDistances[neighborCity] >
                    currentDistance + edgeWeight) {
                    shortestPathDistances[neighborCity] =
                        currentDistance + edgeWeight;
                    priorityQueue.emplace(shortestPathDistances[neighborCity],
                                          neighborCity);
                }
            }
        }
    }
    int getCityWithFewestReachable(
        int n, const vector<vector<int>>& shortestPathMatrix,
        int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for
        // each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }  // Skip self
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};