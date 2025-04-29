class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(int x : nums) cnt[x]++;
        int ans = 0;
        for(auto [_, val] : cnt){
            if(val==1) return -1;
            ans += ceil((double)(val)/3);
        }
        return ans;
    }
};