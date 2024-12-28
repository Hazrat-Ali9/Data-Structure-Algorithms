class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++){
            vector<int> arr(begin(nums)+l[i], begin(nums)+r[i]+1);
            ans.push_back(check(arr));
        }
        return ans;
    }
    bool check(vector<int> arr){
        int mx = INT_MIN, mn = INT_MAX;
        unordered_set<int> s;
        for(int x : arr){
            mx = max(mx, x);
            mn = min(mn, x);
            s.insert(x);
        }
        if((mx-mn) % (arr.size()-1) != 0) return false;
        int diff = (mx - mn) / (arr.size()-1);
        int curr = mn+diff;
        while(curr < mx){
            if(s.find(curr) == s.end()) return false;
            curr += diff;
        }
        return true;
    }
};