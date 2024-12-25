class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupId = m;
        for(int i=0; i<n; i++){
            if(group[i] == -1){
                group[i] = groupId;
                groupId++;
            }
        }
        //sort all item regardless of group dependencies
        map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for(int i=0; i<n; i++){
            itemGraph[i] = vector<int>();
        }
        // Sort all groups regardless of item dependencies.
        map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(groupId, 0);
        for(int i=0; i<groupId; i++){
            groupGraph[i] = vector<int>();
        }
        for(int curr=0; curr<n; curr++){
            for(int prev : beforeItems[curr]){
                // Each (prev -> curr) represents an edge in the item graph.
                itemGraph[prev].push_back(curr);
                itemIndegree[curr]++;
                // If they belong to different groups, add an edge in the group graph.
                if(group[curr] != group[prev]){
                    groupGraph[group[prev]].push_back(group[curr]);
                    groupIndegree[group[curr]]++;
                }
            }
        }
        vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);
        if(itemOrder.empty() || groupOrder.empty()) return vector<int>();
        map<int, vector<int>> orderedGroup;
        for(int item : itemOrder){
            orderedGroup[group[item]].push_back(item);
        }
        vector<int> ans;
        for(int groupIndex : groupOrder){
            ans.insert(ans.end(), orderedGroup[groupIndex].begin(), orderedGroup[groupIndex].end());
        }
        return ans;
    }
    vector<int> topologicalSort(map<int, vector<int>>& graph, vector<int>& indegree){
        vector<int> visited;
        stack<int> stack;
        for(auto entry : graph){
            int key = entry.first;
            if(indegree[key] == 0){
                stack.push(key);
            }
        }
        while(!stack.empty()){
            int curr = stack.top();
            stack.pop();
            visited.push_back(curr);
            for(int prev : graph[curr]){
                indegree[prev]--;
                if(indegree[prev] == 0){
                    stack.push(prev);
                }
            }
        }
        return visited.size() == graph.size() ? visited : vector<int>();
    }
};