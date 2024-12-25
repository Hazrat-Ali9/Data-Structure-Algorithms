class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<mat.size(); i++){
            int cnt = 0;
            for(int j=0; j<mat[0].size(); j++){
                cnt += mat[i][j];
            }
            pq.push({cnt, i});
        }
        vector<int> ans;
        for(int i=0; i<k; i++){
            auto x = pq.top(); pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};