class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //Create a graph representation of character conversions
        vector<vector<pair<int, int>>> adjList(26);
        //Populate the adjacency list with character conversions
        int conversionCount = original.size();
        for(int i=0; i<conversionCount; i++){
            adjList[original[i]-'a'].push_back({changed[i]-'a', cost[i]});
        }
        //Calculate shortest path for all possible character conversions
        vector<vector<long long>> mnConversionCost(26, vector<long long>(26));
        for(int i=0; i<26; i++) mnConversionCost[i] = dijkstra(i, adjList);
        //Calculate the total cost of converting source to target
        long long totalCost = 0;
        int n = source.length();
        for(int i=0; i<n; i++){
            if(source[i] != target[i]){
                long long charConversionCost = mnConversionCost[source[i]-'a'][target[i]-'a'];
                if(charConversionCost == -1) return -1;
                totalCost += charConversionCost;
            }
        }
        return totalCost;
    }
    vector<long long> dijkstra(int src, vector<vector<pair<int, int>>> &adjList){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});
        vector<long long> mnCost(26, -1);
        while(!pq.empty()){
            auto [currCost, currChar] = pq.top();
            pq.pop();
            if(mnCost[currChar] != -1 && mnCost[currChar] < currCost) continue;
            //Explore all posible conversions from the current char
            for(auto [targetChar, conversionCost] : adjList[currChar]){
                long long newTotalCost = currCost + conversionCost;
                if(mnCost[targetChar] == -1 || newTotalCost < mnCost[targetChar]){
                    mnCost[targetChar] = newTotalCost;
                    pq.push({newTotalCost, targetChar});
                }
            }
        }
        return mnCost;
    }
};