class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        vector<int> hash[groupSizes.size()+1];
        for(int i=0; i<groupSizes.size(); i++){
            hash[groupSizes[i]].push_back(i);
            if(hash[groupSizes[i]].size()==groupSizes[i]){
                ans.push_back(hash[groupSizes[i]]);
                hash[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};