class Solution {
public:
    int ans = 0;
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> ds(n, 0);
        f(0, requests, 0, ds);
        return ans;
    }
    void f(int i, vector<vector<int>>& req, int l, vector<int> &ds){
        if(i == req.size()){
            for(int x : ds) if(x != 0) return;
            ans = max(ans, l);
            return;
        }
        f(i+1, req, l, ds);
        ds[req[i][0]]--;
        ds[req[i][1]]++;
        f(i+1, req, l+1, ds);
        ds[req[i][0]]++;
        ds[req[i][1]]--;
    }
};