class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        // Create a map from the bus stop to all the routes that include this stop.
        unordered_map<int, vector<int>> adj;
        for(int route=0; route<routes.size(); route++){
            for(auto stop : routes[route]){
                // Add all the routes that have this stop.
                adj[stop].push_back(route);
            }
        }
        queue<int> q;
        unordered_set<int> vis;
        // Insert all the routes in the queue that have the source stop.
        for(auto route : adj[source]){
            q.push(route);
            vis.insert(route);
        }
        int cnt = 1;
        while(q.size()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int route = q.front(); q.pop();
                for(auto stop : routes[route]){
                    if(stop == target) return cnt;
                    for(auto nxtRoute : adj[stop]){
                        if(!vis.count(nxtRoute)){
                            vis.insert(nxtRoute);
                            q.push(nxtRoute);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};