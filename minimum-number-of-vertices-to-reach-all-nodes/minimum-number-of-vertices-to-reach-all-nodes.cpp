class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDeg(n, 0);
        for(auto e: edges){
            inDeg[e[1]]++;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(inDeg[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};