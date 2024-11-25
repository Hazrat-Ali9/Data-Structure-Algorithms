class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        combination(0, target, candidates, ds, ans);
        return ans;
    }
    void combination(int index, int target, vector<int> arr, vector<int> &ds, vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<arr.size() && target>=arr[i]; i++){
            if(i==index || arr[i] != arr[i-1]){
                ds.push_back(arr[i]);
                combination(i+1, target-arr[i], arr, ds, ans);
                ds.pop_back();
            }
        }
    }
};