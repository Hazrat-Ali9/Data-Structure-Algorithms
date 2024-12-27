class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> mp;
        for(int x : nums) mp[x]++;
        int cnt = 0;
        for(auto x : mp){
            int a = x.second;
            if(a > 1) cnt += (a*(a-1))/2;
        }
        return cnt;
    }
};