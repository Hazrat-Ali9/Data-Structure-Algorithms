class Solution {
public:
    map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x : tickets){
            mp[x[0]].push(x[1]);
        }
        dfs("JFK");
        return ans;
    }
    void dfs(string s){
        auto &x = mp[s];
        while(!x.empty()){
            string to = x.top(); x.pop();
            dfs(to);
        }
        ans.insert(ans.begin(), s);
    }
};