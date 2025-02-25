class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;
        for(auto x : matches) mp[x[1]]++;
        vector<int> winner, loser;
        for(int i=0; i<matches.size(); i++){
            if(mp.find(matches[i][0]) == mp.end()){
                winner.push_back(matches[i][0]);
                mp[matches[i][0]] = 2;
            }
            if(mp[matches[i][1]] == 1) loser.push_back(matches[i][1]);
        }
        sort(winner.begin(), winner.end());
        sort(loser.begin(), loser.end());
        return {winner, loser};
    }
};