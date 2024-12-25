class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> vp;
        for(int i=0; i<nums.size(); i++){
            int mappedValue = 0;
            int temp = nums[i];
            int place = 1;
            if(temp == 0){
                vp.push_back({mapping[0], i});
                continue;
            }
            while(temp != 0){
                mappedValue =place * mapping[temp%10] + mappedValue;
                place *= 10;
                temp /= 10;
            }
            vp.push_back({mappedValue, i});
        }
        sort(vp.begin(), vp.end());
        vector<int> ans;
        for(auto pair : vp) ans.push_back(nums[pair.second]);
        return ans;
    }
};