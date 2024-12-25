class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        set<int> nums(arr.begin(), arr.end());
        int rank = 1;
        for(int num : nums){
            mp[num] = rank++;
        }
        for(int i=0; i<arr.size(); i++) arr[i] = mp[arr[i]];
        return arr;
    }
};