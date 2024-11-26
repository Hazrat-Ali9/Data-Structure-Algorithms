class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        generatePermu(curr, ans, nums);
        return ans;
    }
    void generatePermu(vector<int> &curr, vector<vector<int>> &ans, vector<int> &nums){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int x : nums){
            if(find(curr.begin(), curr.end(), x) == curr.end()){
                curr.push_back(x);
                generatePermu(curr, ans, nums);
                curr.pop_back();
            }
        }
    }
};

// permutation c[[pp]]