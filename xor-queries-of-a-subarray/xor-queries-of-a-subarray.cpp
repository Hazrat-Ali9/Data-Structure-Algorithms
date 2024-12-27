class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for(int i=1; i<n; i++) arr[i] ^= arr[i-1];
        vector<int> ans;
        for(auto &x : queries){
            if(x[0] > 0){
                ans.push_back(arr[x[0]-1] ^ arr[x[1]]);
            }
            else ans.push_back(arr[x[1]]);
        }
        return ans;
    }
};