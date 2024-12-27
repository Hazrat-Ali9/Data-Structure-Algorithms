class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Initialize adjacency list for the graph
        vector<vector<int>> adjacencyList(n);

        // Populate the adjacency list with reversed edges
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[to].push_back(from);
        }

        vector<vector<int>> ancestorsList;

        // For each node, find all its ancestors (children in reversed graph)
        for (int i = 0; i < n; i++) {
            vector<int> ancestors;
            unordered_set<int> visited;
            findChildren(i, adjacencyList, visited);
            // Add visited nodes to the current nodes' ancestor list
            for (int node = 0; node < n; node++) {
                if (node == i) continue;
                if (visited.find(node) != visited.end())
                    ancestors.push_back(node);
            }
            ancestorsList.push_back(ancestors);
        }

        return ancestorsList;
    }

private:
    // Helper method to perform DFS and find all children of a given node
    void findChildren(int currentNode, vector<vector<int>>& adjacencyList,
                      unordered_set<int>& visitedNodes) {
        // Mark current node as visited
        visitedNodes.insert(currentNode);

        // Recursively traverse all neighbors
        for (int neighbour : adjacencyList[currentNode]) {
            if (visitedNodes.find(neighbour) == visitedNodes.end()) {
                findChildren(neighbour, adjacencyList, visitedNodes);
            }
        }
    }
};